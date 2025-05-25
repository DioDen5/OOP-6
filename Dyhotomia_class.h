#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <functional>

class Dyhotomia_class {
private:
    double a, b;
    double epsilon;

public:
    void setVolumes(double a_val, double b_val);
    void setTolerance(double eps);

    double dyhotomiaMethod(const std::function<double(double)>& f);
};

#endif
