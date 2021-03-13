//
// Created by mmaile on 3/12/21.
//

#ifndef THREE_BODY_PROBLEM_MYWINDOW_H
#define THREE_BODY_PROBLEM_MYWINDOW_H

#include <gtkmm.h>
#include <gtkmm-3.0/gtkmm/window.h>


class MyWindow : public Gtk::Window {
protected:
    Gtk::HBox HBoxMaster;
    Gtk::VBox VBoxSettings;

public:
    MyWindow(unsigned int sizeX, unsigned int sizeY);
    ~MyWindow() {};
};


#endif //THREE_BODY_PROBLEM_MYWINDOW_H
