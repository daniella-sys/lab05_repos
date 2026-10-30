#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи рекурсивних функцій
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo);
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void SwapMinMaxInColumnPair(int** a, const int rowCount, int colNo, int i);
void SwapMinMaxColumnsRecursive(int** a, const int rowCount, const int colCount, int colNo);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;

    int k, n;
    cout << "k (rows) = "; cin >> k;
    cout << "n (cols) = "; cin >> n;

    // Динамічне виділення пам'яті для матриці k x n
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Формування матриці рекурсивним способом
    CreateRows(a, k, n, Low, High, 0);
    cout << "\nInitial matrix:";
    PrintRows(a, k, n, 0);

    // Виконання завдання Варіанту 18 рекурсивним способом
    // Починаємо з першого парного стовпця (індекс 1)
    SwapMinMaxColumnsRecursive(a, k, n, 1);

    cout << "Modified matrix:";
    PrintRows(a, k, n, 0);

    // Звільнення динамічної пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Рекурсивне заповнення елементів у рядку
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

// Рекурсивний обхід рядків для заповнення матриці
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

// Рекурсивне виведення елементів рядка
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

// Рекурсивний обхід рядків для виведення матриці
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

// Допоміжна рекурсивна функція пошуку та обміну для конкретної пари стовпців (парного colNo та непарного colNo - 1)
void SwapMinMaxInColumnPair(int** a, const int rowCount, int colNo, int i, int& minRow, int& maxRow)
{
    // Пошук мінімального в парному стовпці (colNo) та максимального в попередньому (colNo - 1)
    if (a[i][colNo] < a[minRow][colNo])
        minRow = i;
    if (a[i][colNo - 1] > a[maxRow][colNo - 1])
        maxRow = i;

    if (i < rowCount - 1)
    {
        SwapMinMaxInColumnPair(a, rowCount, colNo, i + 1, minRow, maxRow);
    }
    else
    {
        // Базовий випадок рекурсії по рядках: коли дійшли до кінця стовпця — робимо обмін (swap)
        int temp = a[minRow][colNo];
        a[minRow][colNo] = a[maxRow][colNo - 1];
        a[maxRow][colNo - 1] = temp;
    }
}

// Рекурсивна функція перебору парних стовпців
void SwapMinMaxColumnsRecursive(int** a, const int rowCount, const int colCount, int colNo)
{
    if (colNo < colCount)
    {
        int minRow = 0;
        int maxRow = 0;

        // Викликаємо рекурсивний пошук по рядках для поточної пари стовпців
        SwapMinMaxInColumnPair(a, rowCount, colNo, 0, minRow, maxRow);

        // Перехід до наступного парного стовпця (крок +2)
        SwapMinMaxColumnsRecursive(a, rowCount, colCount, colNo + 2);
    }
}
