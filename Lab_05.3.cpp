#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);

int main() {
    double tp, tk;
    int n;

    cout << "tp = ";
    cin >> tp;
    cout << "tk = ";
    cin >> tk;
    cout << "n = ";
    cin >> n;

    double dt = (tk - tp) / n;
    double t = tp;

    cout << fixed;
    cout << "----------------------------------------" << endl;
    cout << "|     t     |          result           |" << endl;
    cout << "----------------------------------------" << endl;

    while (t <= tk) {
        double res = f(1.0 + 2.0 * t) + pow(f(f(1.0) + 2.0 * f(2.0 * t)), 2);

        cout << "| " << setw(10) << setprecision(4) << t
            << " | " << setw(24) << setprecision(6) << res << " |" << endl;
        t += dt;
    }

    cout << "----------------------------------------" << endl;
    return 0;
}

double f(const double x) {
    if (fabs(x) >= 1.0) {
        double chyselynyk = pow(sin(x), 2) + sin(x * x);
        double znamenyk = 1.0 + pow(cos(x), 2);
        return chyselynyk / znamenyk;
    }
    else {
        double sum = 0.0;
        double term = x;
        sum += term;

        for (int i = 1; i <= 6; i++) {
            double k = 4.0 * i;
            term *= (x * x * x * x) / ((k - 2.0) * (k - 1.0) * k * (k + 1.0));
            sum += term;
        }

        return (1.0 / (1.0 + x * x)) * sum;
    }
}
