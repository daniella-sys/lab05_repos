#include "pch.h"
#include "CppUnitTest.h"
#include "../CollectionApplication.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab101AUnitTest
{
	TEST_CLASS(Lab101AUnitTest)
	{
	public:

		TEST_METHOD(TestAverage)
		{
			Student s = { "Ivanenko", 2, COMPUTER_SCIENCE, 5, 4, 3 };

			Assert::AreEqual(4.0, Average(s), 1e-12);           // (5 + 4 + 3) / 3
		}

		TEST_METHOD(TestMinAverage)
		{
			Student p[3] = {
				{ "Ivanenko", 2, COMPUTER_SCIENCE, 5, 4, 3 },   // average 4.00
				{ "Koval",    1, LABOR_TRAINING,   4, 4, 2 },   // average 3.33
				{ "Petrenko", 3, INFORMATICS,      4, 5, 4 }    // average 4.33
			};
			int index = -1;

			double result = MinAverage(p, 3, index);

			Assert::AreEqual(10.0 / 3.0, result, 1e-9);
			Assert::AreEqual(1, index);                         // Koval
		}

		TEST_METHOD(TestMinAverageLastStudent)
		{
			Student p[3] = {
				{ "A", 1, COMPUTER_SCIENCE, 5, 5, 5 },          // average 5
				{ "B", 1, COMPUTER_SCIENCE, 4, 4, 4 },          // average 4
				{ "C", 1, COMPUTER_SCIENCE, 3, 3, 3 }           // average 3
			};
			int index = -1;

			double result = MinAverage(p, 3, index);

			Assert::AreEqual(3.0, result, 1e-12);
			Assert::AreEqual(2, index);
		}

		TEST_METHOD(TestMinAverageOneStudent)
		{
			Student p[1] = { { "Only", 1, INFORMATICS, 5, 4, 3 } };
			int index = -1;

			double result = MinAverage(p, 1, index);

			Assert::AreEqual(4.0, result, 1e-12);
			Assert::AreEqual(0, index);
		}

		TEST_METHOD(TestCountGood)
		{
			Student p[3] = {
				{ "Ivanenko", 2, COMPUTER_SCIENCE, 5, 4, 3 },
				{ "Koval",    1, LABOR_TRAINING,   4, 4, 2 },
				{ "Petrenko", 3, INFORMATICS,      4, 5, 4 }
			};
			int physics = 99, math = 99, informatics = 99;      // the function must reset them

			CountGood(p, 3, physics, math, informatics);

			Assert::AreEqual(2, physics);
			Assert::AreEqual(2, math);
			Assert::AreEqual(1, informatics);
		}

		TEST_METHOD(TestCountGoodNone)
		{
			Student p[2] = {
				{ "A", 1, COMPUTER_SCIENCE, 5, 3, 2 },          // no grade equals 4
				{ "B", 1, COMPUTER_SCIENCE, 3, 5, 5 }
			};
			int physics = 99, math = 99, informatics = 99;

			CountGood(p, 2, physics, math, informatics);

			Assert::AreEqual(0, physics);
			Assert::AreEqual(0, math);
			Assert::AreEqual(0, informatics);
		}
	};
}
