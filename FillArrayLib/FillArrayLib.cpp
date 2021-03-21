#include <array>
#include "FillArrayLib.h"


int diagonals_number(int columns, int rows)
{
	return columns + rows - 1;
}


void fillArrayDown(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns, int start_row, int start_column, int& value)
{
	for (int i = 0; start_column - i >= 0 && start_row + i < rows; i++)
	{
		array[start_row + i][start_column - i] = value++;
	}
}

void fillArrayUp(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns, int start_row, int start_column, int& value)
{
	for (int i = 0; start_row - i >= 0 && start_column + i < columns; i++)
	{
		array[start_row - i][start_column + i] = value++;
	}
}


void fillArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{

}
