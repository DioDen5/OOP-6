#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <iostream>
#include <cmath>

using namespace std;

class Dyhotomia_class {
private:
    double a, b;
    double epsilon;

    double f(double x);

public:
    void setVolumes(double a_val, double b_val);
    void setTolerance(double eps);

    double dyhotomiaMethod();
};

#endif
