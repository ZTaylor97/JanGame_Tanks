#ifndef TANK_H
#define TANK_H
#include "SFML/Graphics.hpp"
class Tank
{
public:
    Tank();
    virtual ~Tank();
    void move(bool moveLeft, bool moveRight, float deltaTime);
    void aimBarrel();
    void shoot();
    sf::FloatRect getCoords() {return tank.getGlobalBounds();}
    void setInitialCoords(float xCoord, float yCoord);
    sf::RectangleShape getTank() {return tank;}
    sf::RectangleShape getBarrel() {return barrel;}
private:
    sf::RectangleShape tank;
    sf::RectangleShape barrel;
    float moveSpeed;
    float barrelAngle;
    bool hasShot;
};

#endif // TANK_H
