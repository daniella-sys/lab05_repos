#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи рекурсивних функцій
void CreateRow(int** x, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Create(int** x, const int rowCount, const int colCount, const int Low, const int High, int i);

void PrintRow(int** x, const int rowCount, const int colCount, int i, int j);
void Print(int** x, const int rowCount, const int colCount, int i);

void SortRows(int** x, const int rowCount, const int colCount, int i0, int i1);
void Sort(int** x, const int rowCount, const int colCount, int i0);

void ChangeElement(int** x, const int row1, const int row2, const int colCount, int j);

void CalcElement(int** x, const int rowCount, const int colCount, int& S, int& k, int i, int j);
void CalcRow(int** x, const int rowCount, const int colCount, int& S, int& k, int i);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -12;
    int High = 23;

    int rowCount = 7;
    int colCount = 6;

    // Виділення динамічної пам'яті під матрицю
    int** x = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        x[i] = new int[colCount];

    // 1. Формування та виведення початкової матриці (рекурсивно)
    Create(x, rowCount, colCount, Low, High, 0);
    Print(x, rowCount, colCount, 0);

    // 2. Впорядкування рядків матриці (рекурсивно)
    Sort(x, rowCount, colCount, 0);
    Print(x, rowCount, colCount, 0);

    // 3. Пошук заданих елементів, підрахунок суми, кількості та заміна нулями (рекурсивно)
    int S = 0;
    int k = 0;
    CalcRow(x, rowCount, colCount, S, k, 0);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(x, rowCount, colCount, 0);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] x[i];
    delete[] x;

    return 0;
}

// Рекурсивне створення матриці
void CreateRow(int** x, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    x[i][j] = Low + rand() % (High - Low + 1);
    if (j + 1 < colCount)
        CreateRow(x, rowCount, colCount, Low, High, i, j + 1);
}

void Create(int** x, const int rowCount, const int colCount, const int Low, const int High, int i)
{
    CreateRow(x, rowCount, colCount, Low, High, i, 0);
    if (i + 1 < rowCount)
        Create(x, rowCount, colCount, Low, High, i + 1);
}

// Рекурсивне виведення матриці
void PrintRow(int** x, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << x[i][j];
    if (j + 1 < colCount)
        PrintRow(x, rowCount, colCount, i, j + 1);
    else
        cout << endl;
}

void Print(int** x, const int rowCount, const int colCount, int i)
{
    if (i == 0)
        cout << endl;
    PrintRow(x, rowCount, colCount, i, 0);
    if (i + 1 < rowCount)
        Print(x, rowCount, colCount, i + 1);
    else
        cout << endl;
}

// Рекурсивне сортування (бульбашка через рекурсію)
void SortRows(int** x, const int rowCount, const int colCount, int i0, int i1)
{
    if ((x[i1][0] > x[i1 + 1][0]) ||
        (x[i1][0] == x[i1 + 1][0] && x[i1][1] > x[i1 + 1][1]) ||
        (x[i1][0] == x[i1 + 1][0] && x[i1][1] == x[i1 + 1][1] && x[i1][3] < x[i1 + 1][3]))
    {
        ChangeElement(x, i1, i1 + 1, colCount, 0);
    }

    if (i1 + 1 < rowCount - i0 - 1)
        SortRows(x, rowCount, colCount, i0, i1 + 1);
}

void Sort(int** x, const int rowCount, const int colCount, int i0)
{
    SortRows(x, rowCount, colCount, i0, 0);
    if (i0 + 1 < rowCount - 1)
        Sort(x, rowCount, colCount, i0 + 1);
}

// Рекурсивний обмін рядків (функція Change)
void ChangeElement(int** x, const int row1, const int row2, const int colCount, int j)
{
    int tmp = x[row1][j];
    x[row1][j] = x[row2][j];
    x[row2][j] = tmp;

    if (j + 1 < colCount)
        ChangeElement(x, row1, row2, colCount, j + 1);
}

// Рекурсивний пошук та обчислення (функція Calc)
void CalcElement(int** x, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (x[i][j] % 2 != 0 || x[i][j] >= 0)
    {
        S += x[i][j];
        k++;
        x[i][j] = 0;
    }

    if (j + 1 < colCount)
        CalcElement(x, rowCount, colCount, S, k, i, j + 1);
}

void CalcRow(int** x, const int rowCount, const int colCount, int& S, int& k, int i)
{
    CalcElement(x, rowCount, colCount, S, k, i, 0);

    if (i + 1 < rowCount)
        CalcRow(x, rowCount, colCount, S, k, i + 1);
}
