#include "Rover.hpp"

Rover::Rover(Grid &g) : grid(g), direction(NORTH), position(0, 0) {}

void Rover::setPosition(int x, int y) {
  grid.freeCell(position.getX(), position.getY());
  position.set(x, y);
  grid.occupyCell(x, y);
}

bool Rover::moveForward() {
  int dico_direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int newX = (position.getX() + dico_direction[direction][0] + grid.getSize()) %
             grid.getSize();
  int newY = (position.getY() + dico_direction[direction][1] + grid.getSize()) %
             grid.getSize();

  if (grid.isCellFree(newX, newY)) {
    setPosition(newX, newY);
    return true;
  }
  return false;
}

bool Rover::moveBackward() {
  int dico_direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
  int newX = (position.getX() + dico_direction[direction][0] + grid.getSize()) %
             grid.getSize();
  int newY = (position.getY() + dico_direction[direction][1] + grid.getSize()) %
             grid.getSize();

  if (grid.isCellFree(newX, newY)) {
    setPosition(newX, newY);
    return true;
  }
  return false;
}

void Rover::turnLeft() {
  direction = static_cast<Direction>((direction + 3) % 4);
}

void Rover::turnRight() {
  direction = static_cast<Direction>((direction + 1) % 4);
}

void Rover::display() const {
  position.display();
  std::cout << "Direction: ";
  switch (direction) {
  case NORTH:
    std::cout << "NORTH\n";
    break;
  case EAST:
    std::cout << "EAST\n";
    break;
  case SOUTH:
    std::cout << "SOUTH\n";
    break;
  case WEST:
    std::cout << "WEST\n";
    break;
  }
}
