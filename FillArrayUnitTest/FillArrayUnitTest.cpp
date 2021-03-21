#include "CppUnitTest.h"
#include "../FillArrayLib/FillArrayLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<std::array<std::array<int, maxColumns>, maxRows>>(const std::array<std::array<int, maxColumns>, maxRows>& t)
{
	std::wstring result;
	result += L"{";
	for (auto& row : t)
	{
		result += L"{";
		for (auto& v : row)
		{
			result += ToString(v);
			result += L",";
		}
		result += L"},";
	}
	result += L"}";
	return result;
}



namespace FillArrayUnitTest
{
	TEST_CLASS(FillArrayUnitTest)
	{
	public:
		
		TEST_METHOD(TestDiagonalsNumber)
		{
			int result = diagonalsNumber(5, 6);
			int expected = 10;
			Assert::AreEqual(result, expected);
		}
		TEST_METHOD(TestNextDownStartPoint)
		{
			int start_down_row = 2;
			int start_down_column = 2;
			int expected_column = 0;
			int expected_row = 0;
			nextDownStartPoint(start_down_row, start_down_column);
			nextDownStartPoint(start_down_row, start_down_column);
			Assert::AreEqual(start_down_row, expected_row);
			Assert::AreEqual(start_down_column, expected_column);
		}
		TEST_METHOD(TestNextUpStartPoint)
		{
			int start_up_row = 2;
			int start_up_column = 2;
			int expected_column = 0;
			int expected_row = 2;
			nextUpStartPoint(start_up_row, start_up_column);
			Assert::AreEqual(start_up_row, expected_row);
			Assert::AreEqual(start_up_column, expected_column);
		}
		TEST_METHOD(TestFillArrayDown)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {0, 1}, {2, 0}, {0, 0} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			int start_value = 1;
			fillArrayDown(t1, 3, 2, 0, 1, start_value);
			Assert::AreEqual(t, t1);
		}
		TEST_METHOD(TestFillArrayUp)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {0, 0}, {0, 2}, {1, 0} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			int start_value = 1;
			fillArrayUp(t1, 3, 2, 2, 0, start_value);
			Assert::AreEqual(t, t1);
		}
		TEST_METHOD(TestFillArrayUpOnePoint)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {1, 0}, {0, 0}, {0, 0} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			int start_value = 1;
			fillArrayUp(t1, 3, 2, 0, 0, start_value);
			Assert::AreEqual(t, t1);
		}
		TEST_METHOD(TestFillArrayStandard)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {12, 10, 9}, {11, 8, 4}, {7, 5, 3}, {6, 2, 1} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			fillArray(t1, 4, 3);
			Assert::AreEqual(t, t1);
		}
		TEST_METHOD(TestFillArrayOnePoint)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {1} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			fillArray(t1, 1, 1);
			Assert::AreEqual(t, t1);
		}
		TEST_METHOD(TestFillArrayEmpty)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			fillArray(t1, 0, 0);
			Assert::AreEqual(t, t1);
		}

		TEST_METHOD(TestFillArraySquare)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {16, 15, 11, 10}, {14, 12, 9, 4}, {13, 8, 5, 3}, {7, 6, 2, 1} } };
			std::array<std::array<int, maxColumns>, maxRows> t1 = {};
			fillArray(t1, 4, 4);
			Assert::AreEqual(t, t1);
		}
	};
}
