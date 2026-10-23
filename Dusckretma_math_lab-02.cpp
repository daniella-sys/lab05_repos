#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // Елементи універсуму від 1 до 10
    int U[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "Результат завдання 1: { ";

    for (int x : U) {
        // Базові умови належності числа до початкових множин
        bool in_A = (x >= 1 && x <= 7);
        bool in_B = (x >= 5 && x <= 10);
        bool in_C = (x == 1 || x == 2 || x == 3 || x == 8 || x == 9 || x == 10);

        // 1. Обчислюємо внутрішню ліву частину: (A \ NOT B) \ NOT A
        // A \ NOT B  — це елементи, які є в A, але яких НЕМАЄ в (NOT B) [тобто вони Є в B]
        bool step2 = in_A && in_B;

        // NOT(A \ NOT B) — беремо заперечення від попереднього кроку
        bool step3 = !step2;

        // Віднімаємо NOT A — тобто елемент є в step3, але його НЕМАЄ в (NOT A) [тобто він Є в A]
        bool left = step3 && in_A;

        // 2. Обчислюємо праву частину: B \ NOT C
        // Елементи, які є в B, але яких НЕМАЄ в (NOT C) [тобто вони Є в C]
        bool right = in_B && in_C;

        // 3. Симетрична різниця (ліва частина не дорівнює правій)
        bool inside_huge_bar = (left != right);

        // 4. Найвища риска над усім виразом — заперечення результату симетричної різниці
        bool final_condition = !inside_huge_bar;

        // Якщо число пройшло перевірку — виводимо його
        if (final_condition) {
            cout << x << " ";
        }
    }

    cout << "}" << endl;
    return 0;
}
