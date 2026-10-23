#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 26;

// 1. Рекурсивне формування масиву
void generateArrayRec(int arr[], int size, int i = 0) {
    if (i == size) return;
    arr[i] = 3 + rand() % (92 - 3 + 1);
    generateArrayRec(arr, size, i + 1);
}

// 2. Рекурсивне виведення масиву
void printArrayRec(const int arr[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[i];
    printArrayRec(arr, size, i + 1);
}

// 3. Рекурсивне обчислення кількості
int countElementsRec(const int arr[], int size, int i = 0) {
    if (i == size) return 0;
    int current = (arr[i] % 2 == 0 && i % 7 != 0) ? 1 : 0;
    return current + countElementsRec(arr, size, i + 1);
}

// 4. Рекурсивне обчислення суми
int sumElementsRec(const int arr[], int size, int i = 0) {
    if (i == size) return 0;
    int currentSum = (arr[i] % 2 == 0 && i % 7 != 0) ? arr[i] : 0;
    return currentSum + sumElementsRec(arr, size, i + 1);
}

// 5. Рекурсивна заміна елементів
void replaceElementsRec(int arr[], int size, int i = 0) {
    if (i == size) return;
    if (arr[i] % 2 == 0 && i % 7 != 0) {
        arr[i] = 0;
    }
    replaceElementsRec(arr, size, i + 1);
}

int main() {
    srand(time(0));

    int r[SIZE];

    cout << "Початковий масив (Рекурсія):\n";
    generateArrayRec(r, SIZE);
    printArrayRec(r, SIZE);

    // Рахуємо значення ДО модифікації масиву
    int count = countElementsRec(r, SIZE);
    int sum = sumElementsRec(r, SIZE);

    // Модифікуємо масив
    replaceElementsRec(r, SIZE);

    cout << "\nРезультати:\n";
    cout << "Кількість: " << count << "\n";
    cout << "Сума: " << sum << "\n";

    cout << "\nМодифікований масив:\n";
    printArrayRec(r, SIZE);

    return 0;
}
