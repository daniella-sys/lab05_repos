#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp"


int FindFourthDotFromEnd(const char* str);
char* Change(char* str);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab81IterUnitTest
{
	TEST_CLASS(Lab81IterUnitTest)
	{
	public:

		TEST_METHOD(TestFindFourthDotFromEndAndChange)
		{
			char str1[100] = "a.b.c.d.e";

			int index = FindFourthDotFromEnd(str1);
			Assert::AreEqual(1, index); 

			char* result = Change(str1);

			Assert::AreEqual("a**b**c**d**e", str1);
			Assert::AreEqual("a**b**c**d**e", result);

			delete[] result;
		}

		TEST_METHOD(TestFindFourthDotFromEndNotFound)
		{
			char str2[100] = "a.b.c";

			int index = FindFourthDotFromEnd(str2);
			Assert::AreEqual(-1, index); 

			char* result = Change(str2);

			Assert::AreEqual("a**b**c", str2);
			Assert::AreEqual("a**b**c", result);

			delete[] result;
		}
	};
}
