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
			double expected = (sin(1.0) * sin(1.0) + cos(2.0) * cos(2.0)) / (1.0 + fabs(1.0 * 2.0));

			Assert::AreEqual(expected, g(1.0, 2.0), 1e-6);
		}
	};
}
