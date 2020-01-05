#include "Bullet.h"

Bullet::Bullet(sf::Vector2f Coords, float barrelRotation, float velocity)
    : angle{barrelRotation * (3.1415f/180)}, bulletVelocity{velocity}
{
    bullet.setSize(sf::Vector2f(5,5));
    bullet.setPosition(Coords);
}

Bullet::~Bullet()
{
}

void Bullet::moveBullet(float dt)
{
    float xRatio = sin(angle);
    float yRatio;
    if(sin(angle)<0) yRatio = 1+sin(angle);
    else yRatio = 1-sin(angle);

    float Velocity_X = (bulletVelocity*xRatio*dt);
    float Velocity_Y = (-bulletVelocity *yRatio*dt);
    
    bullet.move(sf::Vector2f(Velocity_X,Velocity_Y-0.5));
}

