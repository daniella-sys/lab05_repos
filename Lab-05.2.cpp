#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Реалізація функції обчислення ряду Тейлора для ln(x) (Блок-схема 3)
double f(const double x) {
    if (x <= 0.0 || x > 2.0) {
        return 0.0;
    }

    double s = 0.0;
    double term = x - 1.0;
    int n = 0;

    while (n < 10) {
        s += term / (n + 1.0);
        term *= -(x - 1.0);
        n++;
    }

    return s;
}

int main() {
    double tp, tk;
    int n;

    // Введення початкових даних
    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    double dt = (tk - tp) / n;
    double t = tp;

    
    cout << fixed << setprecision(5);
    cout << "---------------------------------\n";
    cout << "|" << setw(12) << "t" << " | " << setw(12) << "res" << " |\n";
    cout << "---------------------------------\n";

    
    while (t <= tk) {
        double res = f(1.0 + 2.0 * t) + pow(f(1.0) + 2.0 * f(2.0 * t), 2);

        cout << "|" << setw(12) << t << " | " << setw(12) << res << " |\n";

        t += dt;
    }
    cout << "---------------------------------\n";

    return 0;
}
