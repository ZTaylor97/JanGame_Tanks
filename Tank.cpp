#include "Tank.h"

// TODO: Clean up once basic functionality is in place
Tank::Tank()
{
    // Constructor needs a lot of streamlining
    moveSpeed = 100.0f;
    tank.setSize(sf::Vector2f(30,20));
    tank.setPosition(sf::Vector2f(200,600));
    barrel.setSize(sf::Vector2f(5,20));
    barrel.setPosition(sf::Vector2f(212.5f,585));
}

Tank::~Tank()
{
}

// TODO - this function works as required but it's dodgy, fix it!
void Tank::move(bool moveLeft, bool moveRight, float dt)
{
    if(moveLeft)
    {
        tank.move(-moveSpeed*dt,0);
        barrel.move(-moveSpeed*dt,0);
    }
    if(moveRight)
    {
        tank.move(moveSpeed*dt,0);
        barrel.move(moveSpeed*dt,0);
    }
}

void Tank::aimBarrel()
{
    
}

