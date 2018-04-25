
#include "CppUnitTest.h"
#include "../sortowanie_C++/sortowanie_C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rozmiar = 10;
			cin >> rozmiar;
			int *tablica = new int[rozmiar];
			losowanie(tablica, rozmiar);
			for (int i = 0; i < rozmiar; i++)
			{
				if (tablica[i] < 1 || tablica[i]>10)
					Assert::Fail;
			}
			Assert::IsTrue(true);
		}

	};
}