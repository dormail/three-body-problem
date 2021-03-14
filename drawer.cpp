//
// Created by mmaile on 3/13/21.
//

#include "drawer.h"
#include "ThreeBodyProblem.h"

#define MICROSECOND 0.000001


drawer::drawer() : system(),
    CenterCOM(true),
    h(0.001),
    zoom(200.)
{
    lastTime = std::chrono::system_clock::now();
    system.h = h;
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
        if(CenterCOM) system.CenterCOM();
        dT -= h;
    }

    queue_draw();

    lastTime = std::chrono::system_clock::now();

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
    cr->set_source_rgb(0.8, 0.8, 0.);
    cr->arc(xc + zoom * system.r1[0], yc + zoom * system.r1[1], system.m1, 0, 2 * M_PI);
    cr->stroke();

    cr->set_source_rgb(0.0, 0.3, 0.0);
    cr->arc(xc + zoom * system.r2[0], yc + zoom * system.r2[1], system.m2, 0, 2 * M_PI);
    cr->stroke();

    cr->save();
    cr->set_source_rgb(0.0, 0.0, 0.5);
    cr->arc(xc + zoom * system.r3[0], yc + zoom * system.r3[1], system.m3, 0, 2 * M_PI);
    cr->fill_preserve();
    cr->stroke();



    return true;
}
