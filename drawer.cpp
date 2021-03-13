//
// Created by mmaile on 3/13/21.
//

#include "drawer.h"
#include <chrono>


drawer::drawer() : system()
{
    lastTime = std::chrono::system_clock::now();
}


drawer::~drawer() {}
