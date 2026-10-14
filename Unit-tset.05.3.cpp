#include "pch.h"
#include "CppUnitTest.h"


#include "../CollectionApplication.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CollectionTests
{
	TEST_CLASS(CollectionTests)
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
