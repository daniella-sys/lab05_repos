#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab72RecUnitTest
{
	TEST_CLASS(Lab72RecUnitTest)
	{
	public:

		TEST_METHOD(TestSwapMinMaxColumnsRecursive)
		{

			int k = 3; 
			int n = 2; 

			// Виділяємо динамічну пам'ять під тестову матрицю 3x2
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 5;
			a[1][0] = 15;
			a[2][0] = 10;

			// 1-й стовпець (парний): мін. елемент = 2 (в рядку 2)
			a[0][1] = 20;
			a[1][1] = 8;
			a[2][1] = 2;

			SwapMinMaxColumnsRecursive(a, k, n, 1);

			
			Assert::AreEqual(2, a[1][0]);  
			Assert::AreEqual(15, a[2][1]); 

			// Перевіряємо, чи інші елементи залишилися незмінними
			Assert::AreEqual(5, a[0][0]);
			Assert::AreEqual(10, a[2][0]);
			Assert::AreEqual(20, a[0][1]);
			Assert::AreEqual(8, a[1][1]);

			// Очищення динамічної пам'яті
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
