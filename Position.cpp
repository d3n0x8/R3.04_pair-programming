#include "Position.hpp"

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const { return x; }
int Position::getY() const { return y; }

void Position::set(int newX, int newY) {
  x = newX;
  y = newY;
}

void Position::display() const {
  std::cout << "Position: (" << x << ", " << y << ")\n";
}
