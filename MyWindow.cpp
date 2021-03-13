//
// Created by mmaile on 3/12/21.
//

#include "MyWindow.h"


MyWindow::MyWindow(unsigned int sizeX, unsigned int sizeY)
    : HBoxMaster(false, 30),
    dr(),
    MainFrame()
{
	set_title("Three Body Problem");
	set_default_size(sizeX, sizeY);
	set_border_width(10);

	add(HBoxMaster);
	MainFrame.add(dr);
	HBoxMaster.pack_start(MainFrame);

	show_all_children();
}
