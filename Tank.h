#ifndef TANK_H
#define TANK_H
// std library headers
#include <iostream>
// Project headers
#include "Bullet.h"
// SFML Headers
#include "SFML/Graphics.hpp"
class Tank
{
public:
    Tank();
    virtual ~Tank();
    void move(bool moveLeft, bool moveRight, float deltaTime);
    void aimBarrel(bool aimLeft, bool aimRight, float dt);
    bool shoot(bool isFiring,float dt);
    sf::RectangleShape getTank() {return tank;}
    sf::RectangleShape getBarrel() {return barrel;}
    void moveBullet(float dt);
private:
    sf::RectangleShape tank;
    sf::RectangleShape barrel;
    sf::RectangleShape bullet;
    float moveSpeed;
    float barrelAngle;
    bool hasShot;
};

#endif // TANK_H
