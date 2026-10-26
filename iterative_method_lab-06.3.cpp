#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Прототипи звичайних функцій
void Print(const int* a, const int size);
void SwapPairs(int* a, const int size);

// Прототипи шаблонів функцій
template <typename T>
void Print(const T* a, const int size);

template <typename T>
void SwapPairs(T* a, const int size);

int main()
{
    const int n = 10;

    // 1. Робота зі звичайними функціями (тип int)
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "a       = "; Print(a, n);
    SwapPairs(a, n);
    cout << "Swap(a) = "; Print(a, n);
    cout << endl;

    // 2. Робота з шаблоном (тип int)
    int a2[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "a2<int> = "; Print<int>(a2, n);
    SwapPairs<int>(a2, n);
    cout << "Swap    = "; Print<int>(a2, n);
    cout << endl;

    // 3. Робота з шаблоном (тип double)
    double b[n] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    cout << "b<dbl>  = "; Print<double>(b, n);
    SwapPairs<double>(b, n);
    cout << "Swap    = "; Print<double>(b, n);
    cout << endl;

    // 4. Робота з шаблоном (тип string)
    string c[n] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    cout << "c<str>  = "; Print<string>(c, n);
    SwapPairs<string>(c, n);
    cout << "Swap    = "; Print<string>(c, n);

    return 0;
}

// Реалізація звичайних функцій
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++) 
        cout << setw(5) << a[i];
    cout << endl;
}

void SwapPairs(int* a, const int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
}

// Реалізація шаблонів функцій
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++) 
        cout << setw(5) << a[i];
    cout << endl;
}

template <typename T>
void SwapPairs(T* a, const int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        T temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
}
