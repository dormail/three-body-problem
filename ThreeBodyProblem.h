//
// Created by mmaile on 3/12/21.
//

#ifndef THREE_BODY_PROBLEM_THREEBODYROBLEM_H
#define THREE_BODY_PROBLEM_THREEBODYROBLEM_H

#include <Eigen/Dense>
#define G 1

class ThreeBodyProblem {
public:
    // stuff about the system
    Eigen::Vector3d r1, r2, r3, p1, p2, p3;
    double m1, m2, m3;

    // stuff about the simulation
    double h;
    double t;

    ThreeBodyProblem();

    void EulerIntegration(); // does a single euler integration
    void RungeKuttaIntegration(); // does a single runge kutta integration

    Eigen::Vector3d CenterOfMass();
    void CenterCOM(); // puts the center of mass to (0,0,0)
};


/* calculates the force between with the vector r */
Eigen::Vector3d F(Eigen::Vector3d r, double m1, double m2);


#endif //THREE_BODY_PROBLEM_THREEBODYROBLEM_H
