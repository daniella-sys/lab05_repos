#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Додайте цей рядок сюди:
double f(const double x);

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double x = 2.0;
			double expected = (pow(sin(x), 2) + sin(x * x)) / (1.0 + pow(cos(x), 2));
			Assert::AreEqual(expected, f(x), 1e-6);
		}
	};
}
