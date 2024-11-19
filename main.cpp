// tp pair-programming, duo: Hippolyte Millé et Andréas Rey Malissein
#include <iostream>
#include "Rover.hpp"
#include <string>

int main()
{
    Rover rover;
    std::string commandes;
    std::cout << "Entrez les commandes (f pour avancer, l pour tourner à gauche, r pour tourner à droite, b pour reculer) : ";
    std::cin >> commandes;
    int i = 0;
    while (i < commandes.size())
    {
        switch (commandes[i])
        {
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
        i++;
    }
    rover.display();
    return 0;
}
