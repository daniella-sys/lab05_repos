#include "pch.h"
#include "CppUnitTest.h"

double f(const double x);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double expected = (pow(sin(2.0), 2) + sin(4.0)) / (1.0 + pow(cos(2.0), 2));
			double actual = f(2.0);
			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(TestMethod2)
		{
			double expected = (1.0 / (1.0 + 0.5 * 0.5)) * (0.5 + pow(0.5, 5) / 120.0);
			double actual = f(0.5);
			Assert::AreEqual(expected, actual, 0.0001);
		}
	};
}
