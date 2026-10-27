#include "pch.h"
#include "CppUnitTest.h"

#define main _main
#include "../CollectionApplication.cpp" 
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Project18UnitTest
{
	TEST_CLASS(Project18UnitTest)
	{
	public:

		// 1. Тест для Завдання 1.1: Кількість елементів, менших за C
		TEST_METHOD(TestCountLessThanC)
		{
			// Arrange (Підготовка даних)
			double testArr[] = { 1.5, 4.2, -3.0, 0.5, 10.0 };
			int testSize = 5;
			double c = 2.0;
			int expectedCount = 3; 

			// Act (Виконання дії)
			int actualCount = countLessThanC(testArr, testSize, c);

			// Assert (Перевірка результату)
			Assert::AreEqual(expectedCount, actualCount);
		}

		// 2. Тест для Завдання 1.2: Сума цілих частин елементів після останнього від'ємного
		TEST_METHOD(TestSumAfterLastNegative)
		{
			// Arrange (Підготовка даних
			double testArr[] = { 4.5, -1.2, -2.5, 5.9, 1.1 };
			int testSize = 5;
			bool hasNegative = false;

			int expectedSum = 6;

			// Act (Виконання дії)
			int actualSum = sumAfterLastNegative(testArr, testSize, hasNegative);

			// Assert (Перевірка результату)
			Assert::IsTrue(hasNegative);
			Assert::AreEqual(expectedSum, actualSum);
		}

		// 3. Тест для Завдання 2: Перетворення масиву за умовою 20% від максимуму
		TEST_METHOD(TestTransformArray)
		{
			// Arrange (Підготовка даних)
			double testArr[] = { 3.0, 10.0, 5.0, 9.0, 8.5 };
			int testSize = 5;

			double expectedArr[] = { 10.0, 9.0, 8.5, 3.0, 5.0 };

			// Act (Виконання дії)
			transformArray(testArr, testSize);

			// Assert (Перевірка результату для кожного елемента)
			for (int i = 0; i < testSize; i++)
			{
				// Для типу double використовуємо AreEqual із невеликою похибкою (delta = 0.001)
				Assert::AreEqual(expectedArr[i], testArr[i], 0.001);
			}
		}
	};
}

