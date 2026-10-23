#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 26;

// 1. Формування масиву
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 3 + rand() % (92 - 3 + 1);
    }
}

// 2. Виведення масиву
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

// 3. Обчислення кількості
int countElements(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && i % 7 != 0) {
            count++;
        }
    }
    return count;
}

// 4. Обчислення суми
int sumElements(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && i % 7 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void replaceElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && i % 7 != 0) {
            arr[i] = 0;
        }
    }
}

int main() {
    srand(time(0));

    int r[SIZE];

    cout << "Початковий масив:\n";
    generateArray(r, SIZE);
    printArray(r, SIZE);

    int count = countElements(r, SIZE);
    int sum = sumElements(r, SIZE);

    // Модифікуємо масив
    replaceElements(r, SIZE);

    cout << "\nРезультати:\n";
    cout << "Кількість підходящих елементів: " << count << "\n";
    cout << "Сума підходящих елементів: " << sum << "\n";

    cout << "\nМодифікований масив:\n";
    printArray(r, SIZE);

    return 0;
}
