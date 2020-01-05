#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <cmath>
class Bullet
{
public:
    Bullet(sf::Vector2f Coords, float barrelRotation, float velocity);
    virtual ~Bullet();
    sf::RectangleShape getBullet() {return bullet;}
    void moveBullet(float dt);
private:
    sf::RectangleShape bullet;
    float angle;
    float bulletVelocity;
    enum bulletType {Normal, Large, Fast};
    
};

#endif // BULLET_H
