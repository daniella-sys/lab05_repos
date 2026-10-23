#include <iostream>
#include <cmath>
using namespace std;

// Варіант 18: a(n+2) - 6*a(n+1) + 9*a(n) = 3^n,  a0 = 0, a1 = 3

int main() {
    const int N = 10;
    long long a[N + 1];

    // Спосіб 1: рекурентна формула a(n+2) = 6*a(n+1) - 9*a(n) + 3^n
    a[0] = 0;
    a[1] = 3;
    for (int n = 0; n + 2 <= N; n++)
        a[n + 2] = 6 * a[n + 1] - 9 * a[n] + (long long)pow(3, n);

    // Спосіб 2: розв'язок a(n) = n*(n+17)*3^n / 18
    cout << "n  recurrent  formula" << endl;
    for (int n = 0; n <= N; n++) {
        long long f = (long long)n * (n + 17) * (long long)pow(3, n) / 18;
        cout << n << "  " << a[n] << "  " << f << endl;
    }

    cout << "a2 = " << a[2] << endl;
    return 0;
}
