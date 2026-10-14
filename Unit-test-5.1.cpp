#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double expected = (1.0 / (1.0 + sin(2.0) * sin(2.0))) + (2.0 / (1.0 + 1.0 * 1.0));
			Assert::AreEqual(expected, k(1.0, 2.0), 1e-6);
		}
	};
}
