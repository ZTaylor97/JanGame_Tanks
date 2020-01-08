#include "Bullet.h"

Bullet::Bullet(sf::Vector2f Coords, float barrelRotation, float velocity)
    : angle{barrelRotation}, bulletVelocity{velocity}
{
    bullet.setSize(sf::Vector2f(5,5));
    bullet.setPosition(Coords);
    angle = angle * (3.14159/180);
    xRatio = sin(angle);
    yRatio = -cos(angle);
    bulletVelocity_X = bulletVelocity*xRatio;
    bulletVelocity_Y = bulletVelocity*yRatio;
    windFactor = 0.01f;
}

Bullet::~Bullet()
{
}

// keep windfactor in the same scale of magnitude as gravity
void Bullet::moveBullet(float dt, float windFactor)
{
    bulletVelocity_Y += 175.0f*dt;
    bulletVelocity_X += windFactor*dt;
    bullet.move(sf::Vector2f(bulletVelocity_X*dt, bulletVelocity_Y*dt));
}

