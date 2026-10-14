#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Додаємо саму функцію f(x), яку потрібно протестувати
double f(const double x)
{
    if (x <= 0.0 || x > 2.0) {
        return 0.0; 
    }

    double s = 0.0;
    double term = x - 1.0;

    for (int n = 0; n < 10; n++)
    {
        s += term / (n + 1.0);
        term *= -(x - 1.0);
    }
    
    return s;
}

namespace ЮнітТестиЛогарифм
{
    TEST_CLASS(UnitTestTaylor)
    {
    public:
        
        TEST_METHOD(TestMethodLogarithmSeries)
        {
            // Тест 1: Для x = 1 результат має бути точно 0.0 (ln(1) = 0)
            double expected_1 = 0.0;
            double actual_1 = f(1.0);
            Assert::AreEqual(expected_1, actual_1, 0.0001);

            // Тест 2: Для x = 1.5 значення логарифма близьке до стандартного log(1.5)
            double expected_2 = log(1.5); 
            double actual_2 = f(1.5);
            Assert::AreEqual(expected_2, actual_2, 0.0001);

            // Тест 3: Для точок поза областю збіжності (наприклад, x = 3.0) функція має повернути 0.0
            double expected_3 = 0.0;
            double actual_3 = f(3.0);
            Assert::AreEqual(expected_3, actual_3, 0.0001);
        }
    };
}
