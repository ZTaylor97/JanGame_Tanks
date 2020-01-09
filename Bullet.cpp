#include "Bullet.h"

Bullet::Bullet(sf::Vector2f Coords, float barrelRotation, float velocity, float wind)
    : angle{barrelRotation *(3.14159/180)}, 
    bulletVelocity_X{velocity*sin(angle)}, 
    bulletVelocity_Y{velocity*(-cos(angle))},
    windFactor{wind}
{
    bullet.setSize(sf::Vector2f(5,5));
    bullet.setPosition(Coords);
}

Bullet::~Bullet()
{
}

// keep windfactor in the same scale of magnitude as gravity
void Bullet::moveBullet(float dt, float windFactor)
{
    // acceleration
    bulletVelocity_X += windFactor*dt;
    bulletVelocity_Y += 175.0f*dt;

    sf::Vector2f velocity(bulletVelocity_X*dt, bulletVelocity_Y*dt);
    
    bullet.move(velocity);
}

