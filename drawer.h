//
// Created by mmaile on 3/13/21.
//

#ifndef THREE_BODY_PROBLEM_DRAWER_H
#define THREE_BODY_PROBLEM_DRAWER_H

#include <gtkmm/drawingarea.h>
#include "ThreeBodyProblem.h"
#include <chrono>


class drawer : public Gtk::DrawingArea {
protected:
    ThreeBodyProblem system;
    std::chrono::system_clock::time_point lastTime;

public:
    drawer();
    virtual ~drawer();
};


#endif //THREE_BODY_PROBLEM_DRAWER_H
