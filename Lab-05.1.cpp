#include <iostream>
#include <cmath>

using namespace std;

double g(const double x, const double y);

int main() {
    double r, s;

    cout << "r = ";
    cin >> r;
    cout << "s = ";
    cin >> s;

    double g1 = g(r, s * s + 1.0);
    double part1 = g1 * g1;
    
    double part2 = g(1.0, r * r + s);
    double numerator = part1 + part2;

    double g2 = g(1.0, r * s);
    double denominator = 1.0 + g2 * g2;

    if (denominator == 0) {
        cout << "Помилка: ділення на нуль!" << endl;
        return 1;
    }

    double result = numerator / denominator;

    cout << "Result = " << result << endl;

    return 0;
}

double g(const double x, const double y) {
    double chyselynyk = sin(x) * sin(x) + cos(y) * cos(y);
    double znamenyk = 1.0 + fabs(x * y);
    return chyselynyk / znamenyk;
}
