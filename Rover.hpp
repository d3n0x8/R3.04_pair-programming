#ifndef ROVER_HPP
#define ROVER_HPP

#include "Grid.hpp"
#include "Position.hpp"
#include <iostream>

class Rover {
public:
  Rover(Grid &g);
  bool moveForward();
  bool moveBackward();
  void turnLeft();
  void turnRight();
  void display() const;

private:
  Grid &grid;
  enum Direction { NORTH, EAST, SOUTH, WEST };
  Direction direction;
  Position position;
  void setPosition(int x, int y);
};

#endif