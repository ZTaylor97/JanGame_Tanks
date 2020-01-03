#ifndef TANK_H
#define TANK_H
#include "SFML/Graphics.hpp"
#include <iostream>
class Tank
{
public:
    Tank();
    virtual ~Tank();
    void move(bool moveLeft, bool moveRight, float deltaTime);
    void aimBarrel(bool aimLeft, bool aimRight, float dt);
    void shoot(bool isFiring);
    sf::FloatRect getCoords() {return tank.getGlobalBounds();}
    void setInitialCoords(float xCoord, float yCoord);
    sf::RectangleShape getTank() {return tank;}
    sf::RectangleShape getBarrel() {return barrel;}
    sf::RectangleShape getBullet(){return bullet;}
private:
    sf::RectangleShape tank;
    sf::RectangleShape barrel;
    sf::RectangleShape bullet;
    float moveSpeed;
    float barrelAngle;
    bool hasShot;
};

#endif // TANK_H
