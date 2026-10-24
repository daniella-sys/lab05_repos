#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIter
{
	TEST_CLASS(UnitTestIter)
	{
	public:

		TEST_METHOD(TestIterativeMinMaxIndicesSum)
		{
			
			int testArr[] = { 50, 99, 30, 5 };
			int testSize = 4;

			int expectedResult = 4;

		
			int actualResult = sumMinMaxIndices(testArr, testSize);

			// 3. Assert (Перевірка результату)
			Assert::AreEqual(expectedResult, actualResult);
		}
	};
}
