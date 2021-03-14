//
// Created by mmaile on 3/13/21.
//

#include "drawer.h"
#include "ThreeBodyProblem.h"
//#include <chrono>

#define MICROSECOND 0.000001


drawer::drawer() : system()
{
    lastTime = std::chrono::system_clock::now();
    system.h = MICROSECOND;
    system.t = 0;
}


drawer::~drawer() {}


bool drawer::reCalculate()
{
    double dT = std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now() - lastTime).count() / 1000.0;

    while(dT > 0)
    {
        system.EulerIntegration();
        dT -= MICROSECOND;
    }

    queue_draw();

    return true;
}


bool drawer::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    // getting the size of the drawing area
    Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

    // coordinates for the center of the window
    int xc, yc;
    xc = width / 2;
    yc = height / 2;

    cr->set_line_width(10.0);

    // draw red lines out from the center of the window
    cr->set_source_rgb(0.8, 0.0, 0.0);
    cr->move_to(0, 0);
    cr->line_to(xc, yc);
    cr->line_to(0, height);
    cr->move_to(xc, yc);
    cr->line_to(width, yc);
    cr->stroke();

    return true;
}
