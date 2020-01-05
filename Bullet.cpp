#include "Bullet.h"

Bullet::Bullet(sf::FloatRect Coords, float barrelRotation, float velocity)
    : angle{barrelRotation * (3.1415/180)}, bulletVelocity{velocity}
{
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

