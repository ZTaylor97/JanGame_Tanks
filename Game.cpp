#include "Game.h"

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
    // At the moment this just handles the closing of the window
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
    /* Moving stuff on the screen goes here */

    //  Temporary code to handle player movement, will change this once the game is properly turn based
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

// Doesn't do anything yet but will prevent tanks and projectiles from leaving the screen
void Game::clampToScreen()
{
    
}

// Short helper function to initialise multiple tanks if necessary
void Game::initialiseTanks(int numTanks)
{
    Tank tank;
    for(int i = 0;i<numTanks;i++)
    {
        tanks.push_back(tank);
    }
}