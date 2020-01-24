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
    shootTimer.restart();
}

Tank::~Tank()
{
}

// TODO - this function works as required but it's dodgy, fix it!
void Tank::controlTank(float dt, float turnTime, float cooldownTime)
{
    bool outOfBounds = barrel.getRotation()> 90 && barrel.getRotation() <270;
    clampToScreen(1280,720);
    
    // Tank movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        hasMoved = true;
        tank.move(-moveSpeed*dt,0);
        barrel.move(-moveSpeed*dt,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        hasMoved = true;
        tank.move(moveSpeed*dt,0);
        barrel.move(moveSpeed*dt,0);
    }
    
    // Barrel Rotation
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        hasMoved = true;
        barrel.rotate(-25.0*dt);
        while(outOfBounds) 
        {
            barrel.rotate(0.01);
            outOfBounds = barrel.getRotation()> 90 && barrel.getRotation() <270;
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        hasMoved = true;
        barrel.rotate(25.0*dt);
        while(outOfBounds) 
        {
            barrel.rotate(-0.01);
            outOfBounds = barrel.getRotation()> 90 && barrel.getRotation() <270;
        }
    }
    
    float shootTime = shootTimer.getElapsedTime().asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)&& shootTime >=0.5 && (turnTime >= cooldownTime || hasMoved))
    {
        shoot(dt);
        shootTimer.restart();
    }
}

void Tank::shoot(float dt)
{
    sf::FloatRect temp(barrel.getGlobalBounds());
    sf::Vector2f Coords;
    if(barrel.getRotation()<=90) Coords = sf::Vector2f(barrel.getPosition().x+temp.width,barrel.getPosition().y-temp.height);
    else Coords = sf::Vector2f(temp.left,temp.top);
    Bullet bullet(Coords, barrel.getRotation(), 400, 0.01);
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
