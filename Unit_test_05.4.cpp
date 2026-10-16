#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> 
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int test_k = 15;
			int test_N = 15;

			double actual_result = S0(test_k, test_N); //записуємо те що порахувала наша функція 

			double expected_result = cos(15) / (1 + pow(sin(15), 2)); //записуємо математичну формулу для числа 15

			Assert::AreEqual(expected_result, actual_result, 0.000001); //метод порівнює очікуване значення з фактичним а 3 параметр для точності обрахунку 
		}
	};
}
