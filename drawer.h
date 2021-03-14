//
// Created by mmaile on 3/13/21.
//

#ifndef THREE_BODY_PROBLEM_DRAWER_H
#define THREE_BODY_PROBLEM_DRAWER_H

#include <gtkmm.h>
#include "ThreeBodyProblem.h"
#include <chrono>

class drawer : public Gtk::DrawingArea {
protected:
    ThreeBodyProblem system;
    std::chrono::system_clock::time_point lastTime;

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

    /* attributes for numerical simulation */
    double h; // time interval for each integration step in seconds

    /* attributes for visuals */
    double zoom;
    bool CenterCOM;

public:
    drawer();
    virtual ~drawer();

    bool reCalculate();

};


#endif //THREE_BODY_PROBLEM_DRAWER_H
