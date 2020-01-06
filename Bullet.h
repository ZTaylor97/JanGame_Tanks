#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
class Bullet
{
public:
    Bullet(sf::Vector2f Coords, float barrelRotation, float velocity);
    virtual ~Bullet();
    sf::RectangleShape getBullet() {return bullet;}
    void moveBullet(float dt, float windFactor);
private:
    sf::RectangleShape bullet;
    float angle;
    float bulletVelocity;
    float bulletVelocity_X;
    float bulletVelocity_Y;
    float windFactor;
    enum bulletType {Normal, Large, Fast};
    float xRatio;
    float yRatio;
    
};

#endif // BULLET_H
