#include "Game.h"


Game::Game()
{
}
Game::Game(int windowWidth, int windowHeight, std::string windowName)
    : window(sf::VideoMode(windowWidth,windowHeight), windowName)
{
}
Game::~Game()
{
}

// Game functions
void Game::run()
{
    initialiseTanks(2);
    while(window.isOpen())
    {
        pollEvent();
        dt = clock.restart().asSeconds();
        updateFrame();
        displayFrame();
    }
}

void Game::pollEvent()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}

void Game::updateFrame()
{
    // Moving stuff on the screen goes here
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        tanks.at(0).move(true,false,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        tanks.at(0).move(false,true,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        tanks.at(0).aimBarrel();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        tanks.at(0).aimBarrel();
    }
    clampToScreen();
}

void Game::displayFrame()
{
    window.clear();
    // Drawing stuff to the screen goes here
    window.draw(tanks.at(0).getTank());
    window.draw(tanks.at(0).getBarrel());
    
    window.display();
}

void Game::clampToScreen()
{
    
}

void Game::initialiseTanks(int numTanks)
{
    Tank tank;
    for(int i = 0;i<numTanks;i++)
    {
        tanks.push_back(tank);
    }
}