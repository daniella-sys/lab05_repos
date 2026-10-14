#include <iostream>
#include <iomanip>
#include <cmath> // Містить функції fabs(), pow(), sin(), cos()

using namespace std;

// Прототип функції
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
    cout << "|     t     |         result           |" << endl;
    cout << "----------------------------------------" << endl;

    while (t <= tk) {
        // f(1 + 2*t) + [f(1) + 2*f(2*t)]^2
        double res = f(1.0 + 2.0 * t) + pow(f(1.0) + 2.0 * f(2.0 * t), 2);
        
        cout << "| " << setw(9) << setprecision(4) << t 
             << " | " << setw(22) << setprecision(6) << res << " |" << endl;
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
    } else {
       
        double sum = 0.0;
        double term = x; 
        sum += term;

      
        for (int n = 1; n <= 6; n++) {
            double k = 4 * n;
            
            term *= (x * x * x * x) / ((k - 2) * (k - 1) * k * (k + 1));
            sum += term;
        }

        return (1.0 / (1.0 + x * x)) * sum;
    }
}
