//
// Created by mmaile on 3/12/21.
//

#include "MyWindow.h"


MyWindow::MyWindow(unsigned int sizeX, unsigned int sizeY)
    : HBoxMaster(false, 30),
	VBoxSettings(false, 10)
{
	set_title("Three Body Problem");
	set_default_size(sizeX, sizeY);
	set_border_width(10);

	add(HBoxMaster);
	HBoxMaster.pack_start(VBoxSettings, Gtk::PackOptions::PACK_SHRINK);

	show_all_children();
}
