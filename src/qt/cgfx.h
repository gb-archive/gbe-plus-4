// GB Enhanced+ Copyright Daniel Baxter 2015
// Licensed under the GPLv2
// See LICENSE.txt for full license text

// File : cgfx.h
// Date : July 25, 2015
// Description : Custom graphics settings
//
// Dialog for various custom graphics options

#ifndef CGFX_GBE_QT
#define CGFX_GBE_QT

#include <vector>

#include <SDL2/SDL.h>

#include <QtGui>

#include "common/common.h"
#include "data_dialog.h"

class gbe_cgfx : public QDialog
{
	Q_OBJECT
	
	public:
	gbe_cgfx(QWidget *parent = 0);

	void update_obj_window(int rows, int count);
	void update_bg_window(int rows, int count);

	bool parse_manifest_items();

	void draw_dmg_bg();
	void draw_dmg_win();
	void draw_dmg_obj();

	void draw_gbc_bg();
	void draw_gbc_win();
	void draw_gbc_obj();

	void reset_inputs();

	QTabWidget* tabs;
	QDialogButtonBox* tabs_button;

	//Configure tab widgets
	QCheckBox* advanced;
	QCheckBox* auto_dump_obj;
	QCheckBox* auto_dump_bg;
	QCheckBox* blank;

	//Advanced menu
	QWidget* advanced_box;
	QCheckBox* ext_vram;
	QCheckBox* ext_bright;

	QLabel* dest_label;
	QLineEdit* dest_folder;
	QPushButton* dest_browse;

	QLabel* name_label;
	QLineEdit* dest_name;
	QPushButton* name_browse;

	QDialogButtonBox* advanced_buttons;
	QPushButton* cancel_button;
	QPushButton* dump_button;

	//Layers tab widgets
	QComboBox* layer_select;
	QSpinBox* render_stop_line;
	QLabel* tile_id;
	QLabel* tile_addr;
	QLabel* tile_size;
	QLabel* h_v_flip;
	QLabel* tile_palette;
	QLabel* hash_text;
	QLabel* vram_text;
	QLabel* bright_text;

	QSpinBox* rect_x;
	QSpinBox* rect_w;
	QSpinBox* rect_y;
	QSpinBox* rect_h;

	QCheckBox* use_vram_addr;
	QCheckBox* use_auto_bright;
	QLineEdit* meta_name;

	//OBJ tab widgets
	std::vector<QImage> cgfx_obj;
	std::vector<QPushButton*> obj_button;

	//BG tab widgets
	std::vector<QImage> cgfx_bg;
	std::vector<QPushButton*> bg_button;

	//Manifest tab widgets
	QScrollArea* manifest_display;

	data_dialog* data_folder;

	//Pop-ups
	QMessageBox* manifest_warning;
	QMessageBox* manifest_write_fail;

	bool pause;
	bool enable_manifest_warning;

	QImage grab_obj_data(int obj_index);
	QImage grab_dmg_obj_data(int obj_index);
	QImage grab_gbc_obj_data(int obj_index);

	QImage grab_bg_data(int bg_index);
	QImage grab_dmg_bg_data(int bg_index);
	QImage grab_gbc_bg_data(int bg_index);

	protected:
	void closeEvent(QCloseEvent* event);
	bool eventFilter(QObject* target, QEvent* event);
	void paintEvent(QPaintEvent* event);

	private:
	QWidget* obj_set;
	QWidget* bg_set;
	QWidget* layers_set;

	QGridLayout* obj_layout;
	QGridLayout* bg_layout;
	QGridLayout* layers_layout;

	QSignalMapper* obj_signal;
	QSignalMapper* bg_signal;

	QPushButton* a_input;
	QPushButton* b_input;
	QPushButton* select_input;
	QPushButton* start_input;
	QPushButton* left_input;
	QPushButton* right_input;
	QPushButton* up_input;
	QPushButton* down_input;

	std::vector<u8> estimated_palette;
	std::vector<u8> estimated_vram_bank;

	QLabel* current_layer;
	QLabel* current_tile;

	void setup_obj_window(int rows, int count);
	void update_preview(u32 x, u32 y);
	void dump_layer_tile(u32 x, u32 y);
	std::string hash_tile(u8 x, u8 y);

	void setup_bg_window(int rows, int count);

	u8 dump_type;
	int advanced_index;

	std::string last_custom_path;

	u8 min_x_rect, max_x_rect;
	u8 min_y_rect, max_y_rect;

	u32 mouse_start_x, mouse_start_y;
	bool mouse_drag;

	private slots:
	void close_cgfx();
	void close_advanced();
	void dump_obj(int obj_index);
	void dump_bg(int bg_index);
	void dump_selection();
	void write_manifest_entry();
	void show_advanced_obj(int index);
	void show_advanced_bg(int index);
	void browse_advanced_dir();
	void browse_advanced_file();
	void set_auto_obj();
	void set_auto_bg();
	void set_blanks();
	void layer_change();
	void select_folder();
	void reject_folder();
	void update_selection();
	void ignore_manifest_warnings();
	void advance_next_frame();
	void update_input_control(int index);
};

#endif //CGFX_GBE_QT 
