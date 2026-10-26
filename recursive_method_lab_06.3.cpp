#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Прототипи звичайних рекурсивних функцій
void Print(const int* a, const int size, int i);
void SwapPairs(int* a, const int size, int i);

// Прототипи рекурсивних шаблонів функцій
template <typename T>
void Print(const T* a, const int size, int i);

template <typename T>
void SwapPairs(T* a, const int size, int i);

int main()
{
    const int n = 10;

    // 1. Робота зі звичайними функціями (тип int)
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "a       = "; Print(a, n, 0);
    SwapPairs(a, n, 0);
    cout << "Swap(a) = "; Print(a, n, 0);
    cout << endl;

    // 2. Робота з шаблоном (тип int)
    int a2[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "a2<int> = "; Print<int>(a2, n, 0);
    SwapPairs<int>(a2, n, 0);
    cout << "Swap    = "; Print<int>(a2, n, 0);
    cout << endl;

    // 3. Робота з шаблоном (тип double)
    double b[n] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    cout << "b<dbl>  = "; Print<double>(b, n, 0);
    SwapPairs<double>(b, n, 0);
    cout << "Swap    = "; Print<double>(b, n, 0);
    cout << endl;

    // 4. Робота з шаблоном (тип string)
    string c[n] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    cout << "c<str>  = "; Print<string>(c, n, 0);
    SwapPairs<string>(c, n, 0);
    cout << "Swap    = "; Print<string>(c, n, 0);

    return 0;
}

// Реалізація звичайних рекурсивних функцій для типу int
void Print(const int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        Print(a, size, i + 1); // Рекурсивний крок до наступного елемента
    }
    else
    {
        cout << endl; // Базовий випадок (вихід з рекурсії)
    }
}

void SwapPairs(int* a, const int size, int i)
{
    if (i < size - 1)
    {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        SwapPairs(a, size, i + 2); // Рекурсивний крок через 2 елементи (для наступної пари)
    }
}

// Реалізація рекурсивних шаблонів функцій
template <typename T>
void Print(const T* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        Print(a, size, i + 1);
    }
    else
    {
        cout << endl;
    }
}

template <typename T>
void SwapPairs(T* a, const int size, int i)
{
    if (i < size - 1)
    {
        T temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        SwapPairs(a, size, i + 2);
    }
}
