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
    moveBullet(dt);
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
        barrel.rotate(-15.0*dt);
        if(outOfBounds) barrel.rotate(0.5);
    }
    if(aimRight)
    {
        barrel.rotate(15.0*dt);
        if(outOfBounds) barrel.rotate(-0.5);
    }
}

bool Tank::shoot(bool isFiring, float dt)
{
    hasShot = true;
    sf::FloatRect temp = barrel.getGlobalBounds();
    bullet.setSize(sf::Vector2f(5,5));
    bullet.setPosition(sf::Vector2f(temp.left,temp.top-5));
        
    return true;
}

void Tank::moveBullet(float dt)
{
    if(hasShot)
    {
        float bulletVelocity = 10.0f;
        float angle = barrel.getRotation() * (3.1415/180);
        std::cout <<angle << std::endl;
        float xRatio = sin(angle);
        float yRatio;
        if(sin(angle)<0) yRatio = 1+sin(angle);
        else yRatio = 1-sin(angle);
    
        float Velocity_X = (bulletVelocity*xRatio*dt);
        float Velocity_Y = (-bulletVelocity *yRatio*dt);
        
        bullet.move(sf::Vector2f(Velocity_X,Velocity_Y-0.5));
    }
}