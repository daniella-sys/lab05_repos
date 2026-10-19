#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" // Підключаємо ваш файл із лабораторною

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// 1. Підготовка (Arrange): задаємо тестові числа для множення
			long long test_X = 1234;
			long long test_Y = 5678;
			int start_level = 0;

			// 2. Фактичний результат (Act): записуємо те, що порахував наш алгоритм Карацуби
			long long actual_result = karatsuba(test_X, test_Y, start_level);

			// 3. Очікуваний результат (Expected): записуємо еталонне значення (просте множення)
			long long expected_result = 1234LL * 5678LL;

			// 4. Перевірка (Assert): метод порівнює очікуване значення з фактичним.
			// Оскільки типи цілочисельні (long long), третій параметр точності тут не потрібен!
			Assert::AreEqual(expected_result, actual_result);
		}
	};
}
