#ifndef GAME_H
#define GAME_H
// std library headers
#include <iostream>
#include <string>
#include <vector>
// Project headers
#include "Tank.h"
// SFML headers
#include "SFML/Graphics.hpp"
#include "SFML/Graphics.hpp"

class Game
{
public:
    Game();
    Game(int windowWidth, int windowHeight, std::string windowName);
    void run();
    ~Game();
private:
    // Variables
    std::vector<Tank> tanks;
    sf::RenderWindow window;
    sf::Clock clock;
    float dt;
    //Game functions
    void pollEvent();
    void updateFrame();
    void displayFrame();
    void clampToScreen();
    void initialiseTanks(int numTanks);
};

#endif // GAME_H
