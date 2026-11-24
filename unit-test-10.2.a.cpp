#include "pch.h"
#include "CppUnitTest.h"
#include "../main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentsUnitTest
{
	TEST_CLASS(StudentsUnitTest)
	{
	public:

		TEST_METHOD(TestCompareDifferentSpecialty)
		{
			Student a = { "Ivanenko", 2, INF, 5, 4, 3 };
			Student b = { "Ivanenko", 2, KN,  5, 4, 3 };

			Assert::AreEqual(-1, Compare(a, b, false));         // INF is before KN
			Assert::AreEqual(1,  Compare(b, a, false));
		}

		TEST_METHOD(TestCompareSurname)
		{
			Student a = { "Ivanenko", 2, KN, 5, 4, 3 };
			Student b = { "Petrenko", 2, KN, 4, 5, 4 };

			Assert::AreEqual(-1, Compare(a, b, false));         // alphabetical order
			Assert::AreEqual(1,  Compare(a, b, true));          // reverse alphabetical order
		}

		TEST_METHOD(TestCompareCourse)
		{
			Student a = { "Koval", 1, TN, 4, 4, 2 };
			Student b = { "Koval", 3, TN, 4, 4, 2 };

			Assert::AreEqual(-1, Compare(a, b, false));
			Assert::AreEqual(-1, Compare(a, b, true));          // course is always ascending
		}

		TEST_METHOD(TestCompareEqual)
		{
			Student a = { "Koval", 2, FI, 4, 4, 2 };
			Student b = { "Koval", 2, FI, 5, 5, 5 };            // grades are not part of the key

			Assert::AreEqual(0, Compare(a, b, false));
		}

		TEST_METHOD(TestSortPhysical)
		{
			Student p[4] = {
				{ "Koval",    1, TN, 4, 4, 4 },
				{ "Ivanenko", 2, KN, 5, 4, 3 },
				{ "Petrenko", 3, KN, 4, 5, 4 },
				{ "Ivanenko", 1, KN, 3, 3, 3 }
			};

			SortPhysical(p, 4);

			Assert::AreEqual(std::string("Petrenko"), p[0].surname);    // KN, surname descending
			Assert::AreEqual(std::string("Ivanenko"), p[1].surname);
			Assert::AreEqual(1, p[1].course);                           // same surname, course ascending
			Assert::AreEqual(std::string("Ivanenko"), p[2].surname);
			Assert::AreEqual(2, p[2].course);
			Assert::AreEqual(std::string("Koval"), p[3].surname);       // TN is after KN
		}

		TEST_METHOD(TestSortPhysicalOneStudent)
		{
			Student p[1] = { { "Only", 1, INF, 5, 4, 3 } };

			SortPhysical(p, 1);

			Assert::AreEqual(std::string("Only"), p[0].surname);
		}

		TEST_METHOD(TestBuildIndexArray)
		{
			Student p[4] = {
				{ "Koval",    1, TN, 4, 4, 4 },
				{ "Ivanenko", 2, KN, 5, 4, 3 },
				{ "Petrenko", 3, KN, 4, 5, 4 },
				{ "Ivanenko", 1, KN, 3, 3, 3 }
			};
			int idx[4];

			BuildIndexArray(p, 4, idx);

			Assert::AreEqual(3, idx[0]);                        // Ivanenko, course 1
			Assert::AreEqual(1, idx[1]);                        // Ivanenko, course 2
			Assert::AreEqual(2, idx[2]);                        // Petrenko
			Assert::AreEqual(0, idx[3]);                        // Koval (TN)
			Assert::AreEqual(std::string("Koval"), p[0].surname);   // the array itself is unchanged
		}

		TEST_METHOD(TestBuildIndexArrayOneStudent)
		{
			Student p[1] = { { "Only", 1, INF, 5, 4, 3 } };
			int idx[1] = { -1 };

			BuildIndexArray(p, 1, idx);

			Assert::AreEqual(0, idx[0]);
		}

		TEST_METHOD(TestBinarySearchFound)
		{
			Student p[4] = {
				{ "Koval",    1, TN, 4, 4, 4 },
				{ "Ivanenko", 2, KN, 5, 4, 3 },
				{ "Petrenko", 3, KN, 4, 5, 4 },
				{ "Ivanenko", 1, KN, 3, 3, 3 }
			};
			int idx[4];
			BuildIndexArray(p, 4, idx);
			Student key = { "Petrenko", 3, KN, 0, 0, 0 };

			Assert::AreEqual(2, BinarySearch(p, idx, 4, key));
		}

		TEST_METHOD(TestBinarySearchFirstAndLast)
		{
			Student p[4] = {
				{ "Koval",    1, TN, 4, 4, 4 },
				{ "Ivanenko", 2, KN, 5, 4, 3 },
				{ "Petrenko", 3, KN, 4, 5, 4 },
				{ "Ivanenko", 1, KN, 3, 3, 3 }
			};
			int idx[4];
			BuildIndexArray(p, 4, idx);
			Student first = { "Ivanenko", 1, KN, 0, 0, 0 };
			Student last  = { "Koval",    1, TN, 0, 0, 0 };

			Assert::AreEqual(3, BinarySearch(p, idx, 4, first));
			Assert::AreEqual(0, BinarySearch(p, idx, 4, last));
		}

		TEST_METHOD(TestBinarySearchWrongCourse)
		{
			Student p[4] = {
				{ "Koval",    1, TN, 4, 4, 4 },
				{ "Ivanenko", 2, KN, 5, 4, 3 },
				{ "Petrenko", 3, KN, 4, 5, 4 },
				{ "Ivanenko", 1, KN, 3, 3, 3 }
			};
			int idx[4];
			BuildIndexArray(p, 4, idx);
			Student key = { "Petrenko", 1, KN, 0, 0, 0 };       // Petrenko studies on course 3

			Assert::AreEqual(-1, BinarySearch(p, idx, 4, key));
		}

		TEST_METHOD(TestBinarySearchWrongSpecialty)
		{
			Student p[2] = {
				{ "Koval",    1, TN, 4, 4, 4 },
				{ "Ivanenko", 2, KN, 5, 4, 3 }
			};
			int idx[2];
			BuildIndexArray(p, 2, idx);
			Student key = { "Koval", 1, KN, 0, 0, 0 };          // Koval studies in TN

			Assert::AreEqual(-1, BinarySearch(p, idx, 2, key));
		}

		TEST_METHOD(TestBinarySearchOneStudent)
		{
			Student p[1] = { { "Only", 1, INF, 5, 4, 3 } };
			int idx[1];
			BuildIndexArray(p, 1, idx);
			Student found    = { "Only",  1, INF, 0, 0, 0 };
			Student notFound = { "Other", 1, INF, 0, 0, 0 };

			Assert::AreEqual(0,  BinarySearch(p, idx, 1, found));
			Assert::AreEqual(-1, BinarySearch(p, idx, 1, notFound));
		}
	};
}
