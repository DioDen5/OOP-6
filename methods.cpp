#include "Dyhotomia_class.h"
#include "Newton_class.h"
#include <cmath>
#include <iostream>

using namespace std;

void Dyhotomia_class::setVolumes(double a_val, double b_val) {
    a = a_val;
    b = b_val;
}

void Dyhotomia_class::setTolerance(double eps) {
    epsilon = eps;
}

double Dyhotomia_class::dyhotomiaMethod(const std::function<double(double)>& f) {
    while (!(f(a) * f(b) > 0)) {
        double c = (a + b) / 2;
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        if (fabs(b - a) <= epsilon) {
            return (a + b) / 2;
        }
    }
    return (a + b) / 2; // fallback
}

void Newton_class::setInitialGuess(double x0_val) {
    x0 = x0_val;
}

void Newton_class::setTolerance(double eps) {
    epsilon = eps;
}

double Newton_class::newtonMethod(const std::function<double(double)>& f,
                                  const std::function<double(double)>& df,
                                  int maxIter) const {
    double x = x0;
    for (int i = 0; i < maxIter; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {
            std::cerr << "Похідна занадто мала. Метод Ньютона зупинено." << std::endl;
            break;
        }

        double x_new = x - fx / dfx;
        if (fabs(x_new - x) < epsilon)
            return x_new;

        x = x_new;
    }

    return x;
}

