#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12_4_1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestRemove)
        {
            Elem* L = nullptr;
            Elem* tail = nullptr;
            for (int i = 0; i < 5; i++)
            {
                Insert(L, i);
            }
            int value = 2;
            Remove(L, value);
            bool found = false;
            Elem* current = L;
            while (current != nullptr && current->link != L)
            {
                if (current->info == 1)
                {
                    found = true;
                    break;
                }
                current = current->link;
            }
            Assert::IsFalse(found);
        }
    };
}
