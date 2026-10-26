#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Project2UnitTest
{
	TEST_CLASS(Project2UnitTest)
	{
	public:
		
		TEST_METHOD(TestRecursiveMinMaxIndicesSum)
		{
			// 1. Arrange (Підготовка даних)
			// Задаємо фіксований масив, де ми точно знаємо значення та індекси
			int testArr[] = { 50, 99, 30, 5 }; 
			int testSize = 4;

			// Логіка розрахунку очікуваного результату:
			// Максимум = 99 (знаходиться під індексом 1)
			// Мінімум = 5   (знаходиться під індексом 3)
			// Очікувана сума індексів: 1 + 3 = 4
			int expectedResult = 4;

			// 2. Act (Виконання дії)
			int actualResult = sumMinMaxIndicesRec(testArr, testSize);

			// 3. Assert (Перевірка результату)
			Assert::AreEqual(expectedResult, actualResult);
		}
	};
}
