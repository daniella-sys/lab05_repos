#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

// перелік в алфавітному порядку назв спеціальностей
enum Specialty { INF, KN, ME, TN, FI };

struct Student {
    string surname;
    int course;
    Specialty specialty;
    int physics, math, informatics;
};

int readInt(const string& msg, int lo, int hi) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x && x >= lo && x <= hi) return x;
        cout << "Помилка вводу! Введіть число [" << lo << ".." << hi << "]." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

string specName(Specialty s) {
    const string names[] = { "Інформатика", "Комп. науки", "Мат. та екон.", "Труд. навч.", "Фіз. та інф." };
    return names[s];
}

string InputSurname() {
    string s;
    cin.ignore(10000, '\n');
    do {
        cout << "  Прізвище: ";
        getline(cin, s);
    } while (s.empty());
    return s;
}

Specialty InputSpecialty() {
    cout << "  Спеціальність (0-Інф, 1-КН, 2-МЕ, 3-ТН, 4-ФІ): ";
    return static_cast<Specialty>(readInt("", 0, 4));
}

Student InputSearchKey() {
    Student k{};
    k.surname = InputSurname();
    k.course = readInt("  Курс (1-6): ", 1, 6);
    k.specialty = InputSpecialty();
    return k;
}

void Create(Student* p, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nСтудент № " << i + 1 << ":\n";
        p[i].surname = InputSurname();
        p[i].course = readInt("  Курс (1-6): ", 1, 6);
        p[i].specialty = InputSpecialty();
        p[i].physics = readInt("  Фізика (1-12): ", 1, 12);
        p[i].math = readInt("  Математика (1-12): ", 1, 12);
        p[i].informatics = readInt("  Інформатика (1-12): ", 1, 12);
    }
}

void PrintTable(const Student* p, int n, const string& title, const int* idx = nullptr) {
    const string eq(88, '='), dash(88, '-');
    cout << endl << title << endl << eq << endl;
    cout << "| " << setw(3) << right << "№"
         << " | " << setw(16) << left << "Прізвище"
         << " | " << setw(4) << right << "Курс"
         << " | " << setw(15) << left << "Спеціальність"
         << " | " << setw(7) << right << "Фізика"
         << " | " << setw(10) << right << "Математика"
         << " | " << setw(11) << right << "Інформатика" << " |" << endl << dash << endl;
    for (int i = 0; i < n; i++) {
        int k = idx ? idx[i] : i;
        cout << "| " << setw(3) << right << k + 1
             << " | " << setw(16) << left << p[k].surname
             << " | " << setw(4) << right << p[k].course
             << " | " << setw(15) << left << specName(p[k].specialty)
             << " | " << setw(7) << right << p[k].physics
             << " | " << setw(10) << right << p[k].math
             << " | " << setw(11) << right << p[k].informatics << " |" << endl;
    }
    cout << eq << endl << endl;
}

// порівняння: спеціальність -> прізвище -> курс; surnameDesc = прізвища у зворотному порядку
int Compare(const Student& a, const Student& b, bool surnameDesc) {
    if (a.specialty != b.specialty) return a.specialty < b.specialty ? -1 : 1;
    if (a.surname != b.surname) {
        int r = a.surname < b.surname ? -1 : 1;
        return surnameDesc ? -r : r;
    }
    if (a.course != b.course) return a.course < b.course ? -1 : 1;
    return 0;
}

void SortPhysical(Student* p, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (Compare(p[j], p[j + 1], true) > 0) swap(p[j], p[j + 1]);
}

void BuildIndexArray(const Student* p, int n, int* idx) {
    for (int i = 0; i < n; i++) idx[i] = i;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (Compare(p[idx[j]], p[idx[j + 1]], false) > 0) swap(idx[j], idx[j + 1]);
}

// шукає по індексному масиву; повертає індекс студента в p або -1
int BinarySearch(const Student* p, const int* idx, int n, const Student& key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int c = Compare(p[idx[m]], key, false);
        if (c == 0) return idx[m];
        if (c < 0) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

void ShowMenu() {
    cout << "1 - Сформувати масив\n"
         << "2 - Вивести таблицю\n"
         << "3 - Фізично впорядкувати\n"
         << "4 - Індексне впорядкування\n"
         << "5 - Бінарний пошук студента\n"
         << "0 - Вихід\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = readInt("Введіть кількість студентів: ", 1, 1000);
    Student* p = new Student[n];
    Create(p, n);

    int cmd;
    do {
        ShowMenu();
        cmd = readInt("Вибір: ", 0, 5);
        if (cmd == 1) {
            delete[] p;
            n = readInt("Введіть кількість студентів: ", 1, 1000);
            p = new Student[n];
            Create(p, n);
        } else if (cmd == 2) {
            PrintTable(p, n, "Таблиця студентів");
        } else if (cmd == 3) {
            SortPhysical(p, n);
            PrintTable(p, n, "Фізично впорядкований масив");
        } else if (cmd == 4 || cmd == 5) {
            int* idx = new int[n];
            BuildIndexArray(p, n, idx);
            if (cmd == 4) {
                PrintTable(p, n, "Індексне впорядкування", idx);
            } else {
                int pos = BinarySearch(p, idx, n, InputSearchKey());
                cout << (pos != -1 ? "Так, студент навчається (№ " + to_string(pos + 1) + ")."
                                   : "Такого студента не знайдено.") << endl;
            }
            delete[] idx;
        }
    } while (cmd != 0);

    delete[] p;
    return 0;
}
