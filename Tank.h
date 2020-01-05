#ifndef TANK_H
#define TANK_H
// std library headers
#include <iostream>
#include <vector>
// Project headers
#include "Bullet.h"
// SFML Headers
#include "SFML/Graphics.hpp"
class Tank
{
public:
    Tank(float tank_speed, float x_Pos, float y_Pos);
    virtual ~Tank();
    void move(bool moveLeft, bool moveRight, float deltaTime);
    void aimBarrel(bool aimLeft, bool aimRight, float dt);
    void shoot(float dt);
    sf::RectangleShape getTank() {return tank;}
    sf::RectangleShape getBarrel() {return barrel;}
    std::vector<Bullet> getBullets(){return bullets;}
    void moveBullet(float dt);
private:
    sf::RectangleShape tank;
    sf::RectangleShape barrel;
    std::vector<Bullet> bullets;
    float moveSpeed;
    float barrelAngle;
    bool hasShot;
};

#endif // TANK_H
