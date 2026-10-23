#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountAndSum)
		{
			
			int testArr[] = { 10, 15, 14, 8 };
			int testSize = 4;

			int expectedCount = 2;
			int expectedSum = 22;

			
			int actualCount = countElements(testArr, testSize);
			int actualSum = sumElements(testArr, testSize);

			Assert::AreEqual(expectedCount, actualCount);

			
			Assert::AreEqual(expectedSum, actualSum);
		}
	};
}
