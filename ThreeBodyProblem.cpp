//
// Created by mmaile on 3/12/21.
//

#include "ThreeBodyProblem.h"
#include <math.h>
#include <Eigen/Dense>


Eigen::Vector3d F(Eigen::Vector3d r, double m1, double m2) {
    return -1 * G * r * m1 * m2 / pow(r.norm(), 3);
}


ThreeBodyProblem::ThreeBodyProblem() : m1(1.), m2(1.), m3(1.), h(0.001), t(0)
{
    r1 = Eigen::Vector3d(0,0,0);
    r2 = Eigen::Vector3d(1,0,0);
    r3 = Eigen::Vector3d(0,1,0);

    p1 = Eigen::Vector3d(0,0,0);
    p2 = Eigen::Vector3d(0,1,0);
    p3 = Eigen::Vector3d(1,0,0);
}

void ThreeBodyProblem::EulerIntegration() {
    r1 += h * p1 / m1;
    r2 += h * p2 / m2;
    r3 += h * p3 / m3;

    p1 += h * (F(r1 - r2) + F(r1 - r3));
    p2 += h * (F(r2 - r1) + F(r2 - r3));
    p3 += h * (F(r3 - r1) + F(r3 - r2));

    t += h;
}