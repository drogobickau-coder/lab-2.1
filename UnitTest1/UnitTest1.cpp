#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-2.1/Cursor.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestConstructors)
        {
            Cursor c1;
            Assert::AreEqual(1, c1.GetFirst());
            Assert::AreEqual(1, c1.GetSecond());

            Cursor c2(100, 200);
            Assert::AreEqual(100, c2.GetFirst());
            Assert::AreEqual(200, c2.GetSecond());

            Cursor c3(2000, -5);
            Assert::AreEqual(1, c3.GetFirst());
            Assert::AreEqual(1, c3.GetSecond());
        }

        TEST_METHOD(TestIncrementDecrement)
        {
            Cursor c(10, 10);

            ++c;
            Assert::AreEqual(11, c.GetFirst());
            Assert::AreEqual(10, c.GetSecond());

            --c;
            Assert::AreEqual(10, c.GetFirst());
            Assert::AreEqual(10, c.GetSecond());

            c++;
            Assert::AreEqual(10, c.GetFirst());
            Assert::AreEqual(11, c.GetSecond());

            c--;
            Assert::AreEqual(10, c.GetFirst());
            Assert::AreEqual(10, c.GetSecond());
        }
    };
}