#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1Recur/Lab_07.1Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int** Q = new int* [2];
            for (int i = 0; i < 2; i++) {

                Q[i] = new int[2];
            }
            Q[0][0] = 1;
            Q[0][1] = 2;


            Q[1][0] = 4;
            Q[1][1] = 5;

            int S = 0;
            int k = 0;

            int t = Calc(Q, 2, 2, S, k, 0, 0);
            Assert::AreEqual(t, 6);
		}
	};
}
