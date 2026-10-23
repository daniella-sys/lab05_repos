#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec
{
	TEST_CLASS(UnitTestRec)
	{
	public:

		TEST_METHOD(TestRecursionCountAndSum)
		{

			int testArr[] = { 10, 15, 14, 8 };
			int testSize = 4;

			int expectedCount = 2;
			int expectedSum = 22;


			int actualCount = countElementsRec(testArr, testSize, 0);
			int actualSum = sumElementsRec(testArr, testSize, 0);


			Assert::AreEqual(expectedCount, actualCount);

			Assert::AreEqual(expectedSum, actualSum);
		}
	};
}
