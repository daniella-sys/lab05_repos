#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int max_depth = 0;

// 1. РЕКУРСИВНА ФУНКЦІЯ КАРАЦУБИ ДЛЯ МНОЖЕННЯ ДВОХ ЦІЛИХ ЧИСЕЛ
long long karatsuba(long long X, long long Y, int level) {
    if (level > max_depth) {
        max_depth = level;
    }

    // Базовий випадок (умова виходу з рекурсії)
    // Якщо числа стали однорозрядними (менше 10), просто перемножуємо їх
    if (abs(X) < 10 || abs(Y) < 10) {
        return X * Y;
    }

    // Рахуємо кількість знаків у більшому числі
    int n = max(to_string(abs(X)).length(), to_string(abs(Y)).length());
    int half = n / 2;
    
    // t — основа розбиття (наприклад, 10, 100, 1000)
    long long t = pow(10, half);

    // Розбиваємо числа на старшу (1) та молодшу (0) частини
    long long a1 = X / t;
    long long a0 = X % t;
    long long b1 = Y / t;
    long long b0 = Y % t;

    long long D0 = karatsuba(a0, b0, level + 1);
    long long D1 = karatsuba(a1, b1, level + 1);
    long long D2 = karatsuba(a1 + a0, b1 + b0, level + 1);

    // Фінальна формула Карацуби з підказки методички
    return D1 * t * t + (D2 - D0 - D1) * t + D0;
}

// 2. ФУНКЦІЯ ДЛЯ КОМПЛЕКСНОГО МНОЖЕННЯ
void multiplyComplex(long long a, long long b, long long c, long long d) {
    max_depth = 0;

    long long ac = karatsuba(a, c, 0);
    long long bd = karatsuba(b, d, 0);
    long long ad = karatsuba(a, d, 0);
    long long bc = karatsuba(b, c, 0);

    
    long long r = ac - bd;
    long long s = ad + bc;

    // Виводимо результати на екран
    cout << "\n--- РЕЗУЛЬТАТ ---" << endl;
    cout << "r = " << r << endl;
    cout << "s = " << s << endl;
    cout << "Глибина рекурсії = " << max_depth << endl;
}

int main() {
    long long a, b, c, d;
    
    cout << "Введіть дійсні та уявні частини чисел." << endl;
    cout << "Перше число (a + ib):" << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    
    cout << "Друге число (c + id):" << endl;
    cout << "c = "; cin >> c;
    cout << "d = "; cin >> d;

    // Запускаємо розрахунок
    multiplyComplex(a, b, c, d);

    return 0;
}
