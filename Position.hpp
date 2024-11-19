#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

class Position {
public:
  Position(int x, int y);
  int getX() const;
  int getY() const;
  void set(int newX, int newY);
  void display() const;

private:
  int x;
  int y;
};

#endif