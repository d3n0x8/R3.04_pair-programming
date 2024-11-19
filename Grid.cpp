#include "Grid.hpp"

Grid::Grid(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

bool Grid::isCellFree(int x, int y) const { return grid[x][y] == 0; }

void Grid::occupyCell(int x, int y) { grid[x][y] = 1; }

void Grid::freeCell(int x, int y) { grid[x][y] = 0; }

int Grid::getSize() const { return size; }
