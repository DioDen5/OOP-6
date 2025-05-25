#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

#include <functional>

class Newton_class {
private:
    double x0;
    double epsilon;

public:
    void setInitialGuess(double x0_val);
    void setTolerance(double eps);

    double newtonMethod(const std::function<double(double)>& f,
                        const std::function<double(double)>& df,
                        int maxIter = 1000) const;
};

#endif
