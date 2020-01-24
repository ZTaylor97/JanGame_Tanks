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
    // constructors, destructors etc
    Tank(float tank_speed, float x_Pos, float y_Pos);
    virtual ~Tank();
    // Gameplay related functions
    void controlTank(float deltaTime, float turnTime, float cooldownTime);
    void shoot(float dt);
    void clampToScreen(int screenWidth, int screenHeight);
    // Getters and Setters
    sf::RectangleShape getTank() {return tank;}
    sf::RectangleShape getBarrel() {return barrel;}
    std::vector<Bullet>* getBullets(){return bullets;}
    void set_hasMoved(bool hasMoved_) { hasMoved = hasMoved_;}
    int getShotsTaken() { return shotsTaken;}
    void resetShotsTaken() { shotsTaken=0;}
    float getHealth() {return health;}
    void takeDamage(int damage) {health -=damage;}
    // Public variables -- TODO: remove these unless absolutely necessary
    bool isActive = false;
private:
    sf::RectangleShape tank;
    sf::RectangleShape barrel;
    sf::Clock shootTimer;
    std::vector<Bullet> *bullets;
    float moveSpeed;
    bool hasShot;
    bool hasMoved = false;
    int shotsTaken = 0;
    float health = 200.0f;
};

#endif // TANK_H
