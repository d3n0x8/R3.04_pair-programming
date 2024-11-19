#include <iostream>

class Rover
{
public:
    Rover();
    bool moveForward();
    bool moveBackward();
    void turnLeft();
    void turnRight();
    void display();
    int getX();
    int getY();
    int getDirection();
    bool verifNewPosition(int x, int y);

private:
    int x;
    int y;
    int gridSize = 100;
    int tab[100][100];
    enum Direction
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };
    Direction direction;
    void setPosition(int x, int y);
    void setDirection(Direction direction);
};

Rover::Rover()
{
    x = 0;
    y = 0;
    direction = NORTH;
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            tab[i][j] = 0;
        }
    }
}

bool Rover::verifNewPosition(int x, int y)
{
    if (x < 0 || x >= 100 || y < 0 || y >= 100)
    {
        return false;
    }
    return true;
}

int Rover::getX()
{
    return x;
}

int Rover::getY()
{
    return y;
}

int Rover::getDirection()
{
    return direction;
}

void Rover::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Rover::setDirection(Direction direction)
{
    this->direction = direction;
}

bool Rover::moveForward()
{
    int dico_direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int newX = (getX() + dico_direction[getDirection()][0]) % gridSize;
    int newY = (getY() + dico_direction[getDirection()][1]) % gridSize;
    if (verifNewPosition(newX, newY))
    {
        setPosition(newX, newY);
        return true;
    }
    return false;
}

bool Rover::moveBackward()
{
    int dico_direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int newX = (getX() + dico_direction[getDirection()][0]) % gridSize;
    int newY = (getY() + dico_direction[getDirection()][1]) % gridSize;
    if (verifNewPosition(newX, newY))
    {
        setPosition(newX, newY);
        return true;
    }
    return false;
}

void Rover::turnLeft()
{
    int new_direction = (getDirection() + 3) % 4;
    setDirection(static_cast<Direction>(new_direction));
}

void Rover::turnRight()
{
    int new_direction = (getDirection() + 1) % 4;
    setDirection(static_cast<Direction>(new_direction));
}

void Rover::display()
{
    std::cout << "Position: (" << getX() << ", " << getY() << ")\n";
    std::cout << "Direction: ";
    switch (getDirection())
    {
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

void setGrid(int tab[100][100], int x, int y)
{
    tab[x][y] = 0;
}
