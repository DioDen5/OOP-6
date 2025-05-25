#include <iostream>
#include <cmath>
#include "Dyhotomia_class.h"
#include "Newton_class.h"

using namespace std;

int main() {
    auto f = [](double x) -> double {
        return 3 * x - 4 * log(x) - 5;
    };

    auto df = [](double x) -> double {
        return 3 - 4 / x;
    };

    Dyhotomia_class d;
    d.setVolumes(2, 4);
    d.setTolerance(1e-6);
    double root_d = d.dyhotomiaMethod(f);
    cout << "Корінь методом дихотомії: " << root_d << endl;
    cout << "Перевірка f(" << root_d << ") = " << f(root_d) << endl;

    Newton_class n;
    n.setInitialGuess(3.0);
    n.setTolerance(1e-6);
    double root_n = n.newtonMethod(f, df);
    cout << "Корінь методом Ньютона: " << root_n << endl;
    cout << "Перевірка f(" << root_n << ") = " << f(root_n) << endl;

    return 0;
}
