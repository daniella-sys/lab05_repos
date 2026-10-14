#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int sum(int x, int y);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int t;
			t = sum(2, 3);
			Assert::AreEqual(t, 5);
		}
	};
}
