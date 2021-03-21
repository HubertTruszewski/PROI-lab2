#include <array>

const size_t maxRows = 20;
const size_t maxColumns = 20;


int diagonalsNumber(int columns, int rows);

void nextDownStartPoint(int& start_down_row, int& start_down_column);

void nextUpStartPoint(int& start_up_row, int& start_up_column);

void fillArrayDown(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns, int start_row, int start_column, int& value);

void fillArrayUp(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns, int start_row, int start_column, int& value);

void fillArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);