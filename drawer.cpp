//
// Created by mmaile on 3/13/21.
//

#include "drawer.h"
#include "ThreeBodyProblem.h"
#include <chrono>

#define MICROSECOND 0.000001


drawer::drawer() : system()
{
    lastTime = std::chrono::system_clock::now();
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
