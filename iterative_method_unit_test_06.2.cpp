#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Project1UnitTest
{
	TEST_CLASS(Project1UnitTest)
	{
	public:

		TEST_METHOD(TestSwapPairsIterative)
		{
			// 1. Arrange (Підготовка даних)
			int testArr[] = { 10, 20, 30, 40 };
			int testSize = 4;

			// Очікуваний результат після обміну сусідніх елементів у парах
			int expectedArr[] = { 20, 10, 40, 30 };

			// 2. Act (Виконання дії)
			SwapPairs(testArr, testSize);

			// 3. Assert (Перевірка результату для кожного елемента)
			for (int i = 0; i < testSize; i++)
			{
				Assert::AreEqual(expectedArr[i], testArr[i]);
			}
		}
	};
}
