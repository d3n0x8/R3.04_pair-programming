#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid {
public:
  Grid(int size = 100);
  bool isCellFree(int x, int y) const;
  void occupyCell(int x, int y);
  void freeCell(int x, int y);
  int getSize() const;

private:
  int size;
  std::vector<std::vector<int>> grid;
};

#endif