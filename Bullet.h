#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <cmath>
class Bullet
{
public:
    Bullet(sf::FloatRect Coords, float barrelRotation, float velocity);
    virtual ~Bullet();
    sf::RectangleShape getBullet() {return bullet;}
    void moveBullet(float dt);
private:
    sf::RectangleShape bullet;
    float angle;
    float bulletVelocity;
    
};

#endif // BULLET_H
