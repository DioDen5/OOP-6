#include "Dyhotomia_class.h"
#include "Newton_class.h"

double Dyhotomia_class::f(double x) {
    return 3 * x - 4 * log(x) - 5;
}

void Dyhotomia_class::setVolumes(double a_val, double b_val) {
    a = a_val;
    b = b_val;
}

void Dyhotomia_class::setTolerance(double eps) {
    epsilon = eps;
}

double Dyhotomia_class::dyhotomiaMethod() {
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
}


double Newton_class::f(double x) {
    return 3 * x - 4 * log(x) - 5;
}

double Newton_class::df(double x) {
    return 3 - 4 / x;
}

void Newton_class::setInitialGuess(double x0_val) {
    x0 = x0_val;
}

void Newton_class::setTolerance(double eps) {
    epsilon = eps;
}

double Newton_class::newtonMethod(int maxIter) {
    double x = x0;
    for (int i = 0; i < maxIter; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {
            cerr << "Похідна занадто мала. Метод Ньютона зупинено." << endl;
            break;
        }

        double x_new = x - fx / dfx;

        if (fabs(x_new - x) < epsilon)
            return x_new;

        x = x_new;
    }

    return x;
}
