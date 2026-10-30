#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab71UnitTest
{
	TEST_CLASS(Lab71UnitTest)
	{
	public:

		TEST_METHOD(TestCalcFunction)
		{
			// 1. Arrange (Підготовка даних)
			int rowCount = 2;
			int colCount = 2;

			// Виділяємо динамічну пам'ять під тестову матрицю 2x2
			int** x = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				x[i] = new int[colCount];

			x[0][0] = -2;
			x[0][1] = -3;
			x[1][0] = 4;
			x[1][1] = 5;

			int S = 0;
			int k = 0;

			int expectedS = 6;
			int expectedK = 3;

			// 2. Act (Виконання дії)
			Calc(x, rowCount, colCount, S, k);

			// 3. Assert (Перевірка результату)
			Assert::AreEqual(expectedS, S);
			Assert::AreEqual(expectedK, k);

			Assert::AreEqual(-2, x[0][0]);
			Assert::AreEqual(0, x[0][1]);
			Assert::AreEqual(0, x[1][0]);
			Assert::AreEqual(0, x[1][1]);

			// Очищення динамічної пам'яті
			for (int i = 0; i < rowCount; i++)
				delete[] x[i];
			delete[] x;
		}
	};
}
