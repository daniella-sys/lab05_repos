#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 1. Знайти індекс i, який відповідає 4-й від кінця крапці.
int FindFourthDotFromEnd(const char* str)
{
    size_t len = strlen(str);
    int dotCount = 0;

    for (int i = (int)len - 1; i >= 0; i--)
    {
        if (str[i] == '.')
        {
            dotCount++;
            if (dotCount == 4)
            {
                return i;
            }
        }
    }
    return -1;
}

// 2. Замінити кожну крапку "." парою зірочок "**"
char* Change(char* str)
{
    size_t len = strlen(str);

    int dotCount = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == '.')
            dotCount++;
    }

    char* tmp = new char[len + dotCount + 1];
    char* t = tmp;
    tmp[0] = '\0';

    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == '.')
        {
            strcat(t, "**");
            t += 2;
        }
        else
        {
            *t++ = str[i];
            *t = '\0';
        }
    }

    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int index = FindFourthDotFromEnd(str);
    if (index != -1)
    {
        cout << "Index of the 4th dot from the end: " << index << endl;
    }
    else
    {
        cout << "String contains less than 4 dots." << endl;
    }

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // Звільнення динамічної пам'яті
    return 0;
}
