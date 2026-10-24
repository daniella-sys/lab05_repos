#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Рекурсивне формування масиву
void generateArrayRec(int arr[], int size, int i = 0) {
    if (i == size) return; // Базовий випадок (умова виходу)
    arr[i] = 1 + rand() % 100;
    generateArrayRec(arr, size, i + 1);
}

// 2. Рекурсивне виведення масиву
void printArrayRec(const int arr[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(5) << arr[i];
    printArrayRec(arr, size, i + 1);
}

// 3. Рекурсивне обчислення суми індексів мін. та макс.
int sumMinMaxIndicesRec(const int arr[], int size, int i = 1, int minIdx = 0, int maxIdx = 0) {
    if (i == size) return minIdx + maxIdx;

    // Перевіряємо поточний елемент і оновлюємо індекси мінімуму/максимуму
    if (arr[i] < arr[minIdx]) minIdx = i;
    if (arr[i] > arr[maxIdx]) maxIdx = i;

    return sumMinMaxIndicesRec(arr, size, i + 1, minIdx, maxIdx);
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    srand(time(0));

    const int n = 10;
    int a[n];

    cout << "Сформований масив (Рекурсія):\n";
    generateArrayRec(a, n);
    printArrayRec(a, n);

    int result = sumMinMaxIndicesRec(a, n);

    cout << "\nСума індексів мінімального та максимального елементів (Рекурсія): " << result << endl;

    return 0;
}
