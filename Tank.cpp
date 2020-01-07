#include "Tank.h"

// TODO: Clean up once basic functionality is in place
Tank::Tank(float tank_speed, float x_pos, float y_pos)
    : moveSpeed{tank_speed}
{
    // Constructor needs a lot of streamlining
    tank.setSize(sf::Vector2f(30,20));
    tank.setOrigin(15,5);
    tank.setPosition(sf::Vector2f(x_pos,y_pos));
    barrel.setSize(sf::Vector2f(5,20));
    barrel.setOrigin(sf::Vector2f(2.5,20.0));
    barrel.setPosition(sf::Vector2f(tank.getPosition().x,tank.getPosition().y));
    bullets = new std::vector<Bullet>;
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
    else if(aimRight)
    {
        barrel.rotate(25.0*dt);
        if(outOfBounds) barrel.rotate(-0.5);
    }
}

void Tank::shoot(float dt)
{
    sf::FloatRect temp(barrel.getGlobalBounds());
    sf::Vector2f Coords(temp.left,temp.top);
    float angle = barrel.getRotation();
    Bullet bullet(Coords, angle, 20);
    bullets->push_back(bullet);
    shotsTaken++;
}

void Tank::clampToScreen(int screenWidth, int screenHeight)
{
    sf::FloatRect coords = tank.getGlobalBounds();
    float tankWidth = (coords.width/2);
    if(coords.left + coords.width> screenWidth)
    {
        tank.setPosition(screenWidth-tankWidth, tank.getPosition().y);
        barrel.setPosition(screenWidth-tankWidth,barrel.getPosition().y);
    } else if (coords.left < 0)
    {
        tank.setPosition(0+tankWidth,tank.getPosition().y);
        barrel.setPosition(0+tankWidth,barrel.getPosition().y);
    }
}
