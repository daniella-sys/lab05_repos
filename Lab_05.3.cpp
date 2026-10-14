#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототип функції
double f(const double x);

int main()
{
    double tp, tk;
    int n;
    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    double dt = (tk - tp) / n;
    double t = tp;

    cout << fixed;
    cout << "----------------------------------------" << endl;
    cout << "|      t      |         result         |" << endl;
    cout << "----------------------------------------" << endl;

    while (t <= tk)
    {
        // Обчислення виразу: f(1 + 2*t) + [f(1) + 2*f(2*t)]^2
        double res = f(1.0 + 2.0 * t) + pow(f(1.0) + 2.0 * f(2.0 * t), 2);
        
        cout << "| " << setw(11) << setprecision(4) << t
             << " | " << setw(22) << setprecision(6) << res << " |" << endl;
        t += dt;
    }

    cout << "----------------------------------------" << endl;
    return 0;
}

// Реалізація функції обчислення ряду Тейлора для ln(x)
double f(const double x)
{
    // Перевірка області збіжності, вказаної на малюнку (0 < x <= 2)
    if (x <= 0.0 || x > 2.0) {
        return 0.0; 
    }

    double s = 0.0;
    double term = x - 1.0; // Перший чисельник при n = 0

    // Обчислюємо перші 10 членів ряду для досягнення хорошої точності
    for (int n = 0; n < 10; n++)
    {
        s += term / (n + 1.0);
        term *= -(x - 1.0); // Наступний чисельник із протилежним знаком і більшим степенем
    }
    
    return s;
}
