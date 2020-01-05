#include "Tank.h"

// TODO: Clean up once basic functionality is in place
Tank::Tank()
{
    // Constructor needs a lot of streamlining
    moveSpeed = 100.0f;
    tank.setSize(sf::Vector2f(30,20));
    tank.setPosition(sf::Vector2f(200,600));
    barrel.setSize(sf::Vector2f(5,20));
    barrel.setOrigin(sf::Vector2f(2.5,20.0));
    barrel.setPosition(sf::Vector2f(215,605));
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

void Tank::aimBarrel(bool aimLeft, bool aimRight, float dt)
{
    bool outOfBounds = barrel.getRotation()> 90 && barrel.getRotation() <270;
    if(aimLeft)
    {
        barrel.rotate(-25.0*dt);
        if(outOfBounds) barrel.rotate(0.5);
    }
    if(aimRight)
    {
        barrel.rotate(25.0*dt);
        if(outOfBounds) barrel.rotate(-0.5);
    }
}

bool Tank::shoot(bool isFiring, float dt)
{
    hasShot = true;
    sf::FloatRect temp = barrel.getGlobalBounds();
    float angle = barrel.getRotation();
    Bullet bullet(temp,angle, 10);
    return true;
}