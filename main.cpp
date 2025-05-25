#include "Dyhotomia_class.h"
#include "Newton_class.h"

double f(double x) {
    return 3 * x - 4 * log(x) - 5;
}

int main() {
    Dyhotomia_class d;
    d.setVolumes(2, 4);
    d.setTolerance(1e-6);
    double root_d = d.dyhotomiaMethod();
    cout << "Корінь методом дихотомії: " << root_d << endl;
    cout << "Перевірка f(" << root_d << ") = " << f(root_d) << endl;

    Newton_class n;
    n.setInitialGuess(3.0);
    n.setTolerance(1e-6);
    double root_n = n.newtonMethod();
    cout << "Корінь методом Ньютона: " << root_n << endl;
    cout << "Перевірка f(" << root_n << ") = " << f(root_n) << endl;

    return 0;
}
