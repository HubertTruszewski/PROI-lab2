#include <array>
#include "FillArrayLib.h"


int diagonalsNumber(int columns, int rows)
{
	return columns + rows - 1;
}

void nextDownStartPoint(int& start_down_row, int& start_down_column, size_t rows, size_t columns)
{
	if (columns == 1)
	{
		start_down_row -= 2;
	}
	else if (rows == 1)
	{
		start_down_column -= 2;
	}
	else if (start_down_row > 1)
	{
		start_down_row -= 2;
	}
	else if (start_down_row == 1)
	{
		start_down_row--;
		start_down_column--;
	}
	else
	{
		start_down_column -= 2;
	}
}

void nextUpStartPoint(int& start_up_row, int& start_up_column, size_t rows, size_t columns)
{
	if (columns == 1)
	{
		start_up_row -= 2;
	}
	else if (rows == 1)
	{
		start_up_column -= 2;
	}
	else if (start_up_column > 1)
	{
		start_up_column -= 2;
	}
	else if (start_up_column == 1)
	{
		start_up_column--;
		start_up_row--;
	}
	else
	{
		start_up_row -= 2;
	}
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
	int diagonals = diagonalsNumber(columns, rows);
	int value = 1;
	int start_up_column, start_up_row, start_down_row, start_down_column;
	if (columns == 1)
	{
		start_up_column = 0;
		start_up_row = int(rows) - 2;
	}
	else
	{
		start_up_column = (int)columns - 2;
		start_up_row = int(rows) - 1;
	}
	
	if (rows == 1)
	{
		start_down_row = 0;
	}
	else
	{
		start_down_row = (int)rows - 1;
	}
	start_down_column = (int)columns - 1;

	for (int i = 0; i < diagonals; i++)
	{
		if (i % 2 == 0) // dla parzystych
		{
			fillArrayDown(array, rows, columns, start_down_row, start_down_column, value);

			nextDownStartPoint(start_down_row, start_down_column, rows, columns);
		}
		else
		{
			fillArrayUp(array, rows, columns, start_up_row, start_up_column, value);

			nextUpStartPoint(start_up_row, start_up_column, rows, columns);
		}
	}
}
