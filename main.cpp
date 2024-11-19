#include "Rover.hpp"

int main() {
  Grid grid(100);
  Rover rover(grid);

  std::string commandes;
  std::cout << "Entrez les commandes (f pour avancer, l pour tourner à gauche, "
               "r pour tourner à droite, b pour reculer) : ";
  std::cin >> commandes;

  for (char command : commandes) {
    switch (command) {
    case 'f':
      rover.moveForward();
      break;
    case 'b':
      rover.moveBackward();
      break;
    case 'l':
      rover.turnLeft();
      break;
    case 'r':
      rover.turnRight();
      break;
    default:
      break;
    }
  }
  rover.display();

  return 0;
}
