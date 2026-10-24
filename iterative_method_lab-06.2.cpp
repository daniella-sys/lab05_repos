#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Формування масиву випадковими числами (від 1 до 100)
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 1 + rand() % 100;
    }
}

// 2. Виведення масиву у вигляді рядка з форматним виведенням
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

// 3. Обчислення суми індексів макс. та мін. елементів
int sumMinMaxIndices(const int arr[], int size) {
    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i; // Запам'ятовуємо індекс нового мінімуму
        }
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i; // Запам'ятовуємо індекс нового максимуму
        }
    }
    
    return minIdx + maxIdx; // Повертаємо суму індексів у місце виклику
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    srand(time(0));

    const int n = 10; // Розмір масиву
    int a[n];

    cout << "Сформований масив:\n";
    generateArray(a, n);
    printArray(a, n);

    // Викликаємо функцію, яка обчислює і повертає результат
    int result = sumMinMaxIndices(a, n);

    cout << "\nСума індексів мінімального та максимального елементів: " << result << endl;

    return 0;
}
