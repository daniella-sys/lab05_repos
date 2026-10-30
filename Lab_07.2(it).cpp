#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMinMaxColumns(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;

    int k, n;
    cout << "k (rows) = "; cin >> k;
    cout << "n (cols) = "; cin >> n;

    // Динамічне виділення пам'яті для двовимірного масиву (матриці k x n)
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    cout << "\nInitial matrix:";
    Print(a, k, n);

    SwapMinMaxColumns(a, k, n);

    cout << "Modified matrix:";
    Print(a, k, n);

    // Звільнення динамічної пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція формування матриці випадковими числами у діапазоні [Low, High]
void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція виведення матриці на екран у вигляді таблиці
void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для пошуку мінімального елемента в парному стовпці 
// та максимального в попередньому непарному, і їх взаємної заміни
void SwapMinMaxColumns(int** a, const int k, const int n)
{
    // j = 1 відповідає 2-му (парному) стовпцю за порядком.
    // j - 1 = 0 відповідає 1-му (попередньому непарному) стовпцю.
    for (int j = 1; j < n; j += 2)
    {
        int minRow = 0;
        int minVal = a[0][j];
        // Пошук мінімального елемента у поточному парному стовпці (індекс j)
        for (int i = 1; i < k; i++)
        {
            if (a[i][j] < minVal)
            {
                minVal = a[i][j];
                minRow = i;
            }
        }

        int maxRow = 0;
        int maxVal = a[0][j - 1];
        // Пошук максимального елемента у попередньому непарному стовпці (індекс j - 1)
        for (int i = 1; i < k; i++)
        {
            if (a[i][j - 1] > maxVal)
            {
                maxVal = a[i][j - 1];
                maxRow = i;
            }
        }

        // Обмін місцями знайдених елементів
        int temp = a[minRow][j];
        a[minRow][j] = a[maxRow][j - 1];
        a[maxRow][j - 1] = temp;
    }
}
