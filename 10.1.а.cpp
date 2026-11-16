// Lab 10.1, variant 18, level A
// 1. Find the smallest average grade (comparing the average grades of all students).
// 2. Count the grades "good" (4) for each subject.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialty { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS,
                 PHYSICS_INFORMATICS, LABOR_TRAINING };

const string specialtyStr[] = { "Computer Science", "Informatics",
                                "Math and Economics",
                                "Physics and Informatics", "Labor Training" };

struct Student
{
    string    surname;
    int       course;
    Specialty specialty;
    int       physics;
    int       math;
    int       informatics;
};

void   Create(Student* p, const int N);
void   Print(const Student* p, const int N);
double Average(const Student& s);
double MinAverage(const Student* p, const int N, int& index);
void   CountGood(const Student* p, const int N,
                 int& physics, int& math, int& informatics);

int main()
{
    int N;
    cout << "Enter the number of students: "; cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    int index;
    double minAvg = MinAverage(p, N, index);
    cout << fixed << setprecision(2);
    cout << "1) Smallest average grade: " << minAvg
         << " (" << p[index].surname << ")" << endl;

    int physics, math, informatics;
    CountGood(p, N, physics, math, informatics);
    cout << "2) Number of \"good\" grades:" << endl
         << "   physics: " << physics << endl
         << "   math: " << math << endl
         << "   informatics: " << informatics << endl;

    delete[] p;
    return 0;
}

// Fills the array of structures with data entered by the user.
void Create(Student* p, const int N)
{
    int specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Student # " << i + 1 << ":" << endl;
        cout << "  surname: ";   cin >> p[i].surname;
        cout << "  course: ";    cin >> p[i].course;
        cout << "  specialty (0 - Computer Science, 1 - Informatics, "
                "2 - Math and Economics, 3 - Physics and Informatics, "
                "4 - Labor Training): ";
        cin >> specialty;
        p[i].specialty = (Specialty)specialty;
        cout << "  physics grade: ";      cin >> p[i].physics;
        cout << "  math grade: ";         cin >> p[i].math;
        cout << "  informatics grade: ";  cin >> p[i].informatics;
        cout << endl;
    }
}

// Prints the array as a table with a title and a header.
void Print(const Student* p, const int N)
{
    string line(94, '=');
    cout << "Students' grades" << endl;
    cout << line << endl;
    cout << left
         << "| " << setw(3)  << "No"
         << "| " << setw(14) << "Surname"
         << "| " << setw(7)  << "Course"
         << "| " << setw(24) << "Specialty"
         << "| " << setw(8)  << "Physics"
         << "| " << setw(11) << "Math"
         << "| " << setw(12) << "Informatics" << "|" << endl;
    cout << line << endl;
    for (int i = 0; i < N; i++)
        cout << "| " << setw(3)  << i + 1
             << "| " << setw(14) << p[i].surname
             << "| " << setw(7)  << p[i].course
             << "| " << setw(24) << specialtyStr[p[i].specialty]
             << "| " << setw(8)  << p[i].physics
             << "| " << setw(11) << p[i].math
             << "| " << setw(12) << p[i].informatics << "|" << endl;
    cout << line << endl;
}

// Returns the average grade of one student.
double Average(const Student& s)
{
    return (s.physics + s.math + s.informatics) / 3.0;
}

// Returns the smallest average grade; index gets the number of that student.
double MinAverage(const Student* p, const int N, int& index)
{
    index = 0;
    double minAvg = Average(p[0]);
    for (int i = 1; i < N; i++)
        if (Average(p[i]) < minAvg)
        {
            minAvg = Average(p[i]);
            index = i;
        }
    return minAvg;
}

// Counts the grades "good" (4) for each subject (results via output parameters).
void CountGood(const Student* p, const int N,
               int& physics, int& math, int& informatics)
{
    physics = math = informatics = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 4)     physics++;
        if (p[i].math == 4)        math++;
        if (p[i].informatics == 4) informatics++;
    }
}
