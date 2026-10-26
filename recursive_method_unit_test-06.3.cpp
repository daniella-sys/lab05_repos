#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Project2UnitTest
{
	TEST_CLASS(Project2UnitTest)
	{
	public:

		TEST_METHOD(TestSwapPairsRecursive)
		{
			// 1. Arrange (Підготовка даних)
			int testArr[] = { 10, 20, 30, 40 };
			int testSize = 4;

			// Очікуваний результат після рекурсивного обміну сусідніх елементів у парах
			int expectedArr[] = { 20, 10, 40, 30 };

			// 2. Act (Виконання дії)
			// Передаємо 0 як початковий індекс для старту рекурсії
			SwapPairs(testArr, testSize, 0);

			// 3. Assert (Перевірка результату для кожного елемента)
			for (int i = 0; i < testSize; i++)
			{
				Assert::AreEqual(expectedArr[i], testArr[i]);
			}
		}
	};
}
