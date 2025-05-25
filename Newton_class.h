#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

#include <iostream>
#include <cmath>

class Newton_class {
private:
    double x0;
    double epsilon;

    double f(double x);
    double df(double x);

public:
    void setInitialGuess(double x0_val);
    void setTolerance(double eps);

    double newtonMethod(int maxIter = 1000);
};

#endif
