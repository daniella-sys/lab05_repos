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
			int n = 0;
			double expected = 0.0;
			Assert::AreEqual(expected, S(1.0, 1e-5, n), 1e-6);
		}
	};
}
