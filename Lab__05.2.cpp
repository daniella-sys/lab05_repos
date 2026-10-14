#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n);
double A(const double x, const int n, double& a);

int main() {
    double xp, xk, dx, eps, s;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------\n";
    cout << "|   x   |   log(x)  |     S     |   n   |\n";
    cout << "-------------------------------------------------\n";

    double x = xp;
    while (x <= xk) {
        s = S(x, eps, n);

        cout << "| " << setw(5) << setprecision(2) << x
            << " | " << setw(9) << setprecision(5) << log(x)
            << " | " << setw(9) << setprecision(5) << s
            << " | " << setw(5) << n << " |\n";

        x += dx;
    }
    cout << "-------------------------------------------------\n";

    return 0;
}

double S(const double x, const double eps, int& n) {
    n = 0;
    double a = x - 1.0;
    double s = a;

    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);

    return s;
}

double A(const double x, const int n, double& a) {
    double R = -((x - 1.0) * n) / (n + 1);
    a *= R;
    return a;
}
