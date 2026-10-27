#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для форматного виведення масиву в один рядок
void printArray(const double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << setw(8) << arr[i];
    }
    cout << "\n";
}

// Завдання 1.1: Кількість елементів, менших за C
int countLessThanC(const double* arr, int n, double c) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < c) count++;
    }
    return count;
}

// Завдання 1.2: Сума цілих частин елементів після останнього від'ємного
int sumAfterLastNegative(const double* arr, int n, bool& hasNegative) {
    int lastNegIdx = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < 0) { lastNegIdx = i; break; }
    }
    
    if (lastNegIdx == -1) {
        hasNegative = false;
        return 0;
    }
    
    hasNegative = true;
    int sum = 0;
    for (int i = lastNegIdx + 1; i < n; i++) {
        sum += (int)arr[i]; // Беремо лише цілу частину
    }
    return sum;
}

// Завдання 2: Перетворення масиву за умовою 20% від максимуму
void transformArray(double* arr, int n) {
    double maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    
    double* temp = new double[n];
    int tIdx = 0;
    
    // Переносимо елементи, що відрізняються від MAX не більше ніж на 20%
    for (int i = 0; i < n; i++) {
        if (abs(maxVal - arr[i]) <= 0.2 * abs(maxVal)) temp[tIdx++] = arr[i];
    }
    // Переносимо всі інші елементи
    for (int i = 0; i < n; i++) {
        if (abs(maxVal - arr[i]) > 0.2 * abs(maxVal)) temp[tIdx++] = arr[i];
    }
    
    // Копіюємо назад та видаляємо тимчасовий масив
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    delete[] temp;
}

int main() {
    setlocale(LC_ALL, "Ukranian");
    int n;
    double c;
    
    cout << "Введіть розмір масиву n та число C: ";
    cin >> n >> c;
    
    // Виділення пам'яті та введення елементів
    double* array = new double[n];
    cout << "Введіть " << n << " елементів:\n";
    for (int i = 0; i < n; i++) cin >> array[i];
    
    cout << "\nПочатковий масив:\n";
    printArray(array, n);
    
    // Обчислення результатів
    bool hasNeg = false;
    int countC = countLessThanC(array, n, c);
    int sumNeg = sumAfterLastNegative(array, n, hasNeg);
    
    cout << "\nКількість елементів < C: " << countC << "\n";
    if (hasNeg) cout << "Сума цілих частин після від'ємного: " << sumNeg << "\n";
    else cout << "У масиві немає від'ємних елементів.\n";
    
    // Модифікація та виведення результату
    transformArray(array, n);
    cout << "\nМодифікований масив:\n";
    printArray(array, n);
    
    delete[] array; // Звільнення динамічної пам'яті
    return 0;
}
