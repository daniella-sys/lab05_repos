#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Додаємо цей рядок, щоб підказати компілятору, як виглядає функція f
double f(const double x);

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double x = 1.0;
			double expected = 0.0;
			Assert::AreEqual(expected, f(x), 1e-6);
		}
	};
}

