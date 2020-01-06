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
    shootTimer.restart();
    initialiseTanks(2);
    while(window.isOpen())
    {
        pollEvent();
        dt = dtClock.restart().asSeconds();
        updateFrame();
        tanks.at(0).getBarrel().getGlobalBounds();
        displayFrame();
    }
}

void Game::pollEvent()
{
    // At the moment this just handles the closing of the window
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            break;
        }
    }
}

void Game::updateFrame()
{
    /* Moving stuff on the screen goes here */
    controlTank(0);
    for(auto tank: tanks)
    {
        for(size_t i = 0; i<tank.getBullets()->size(); i++)
        {
            tank.getBullets()->at(i).moveBullet(dt, 0.001);
        }
    }
    //  Temporary code to handle player movement, will change this once the game is properly turn based
    
    clampToScreen();
}

void Game::displayFrame()
{
    window.clear();
    // Drawing stuff to the screen goes here
    
    // Draws every tank, and every bullet of every tank
    for(auto tank: tanks)
    {
        window.draw(tank.getTank());
        window.draw(tank.getBarrel());
        // Draws bullets, deletes them if they are out of bounds
        for(size_t i = 0; i< (tank.getBullets()->size()); i++)
        {
            sf::Vector2f coords = tank.getBullets()->at(i).getBullet().getPosition();
            bool outOfBounds = coords.x< 0 || coords.x >1280 || coords.y<0 || coords.y >720;
            window.draw(tank.getBullets()->at(i).getBullet());
            if(outOfBounds)
            {
                tank.getBullets()->erase(tank.getBullets()->begin()+i);
            }
        }
    }
    window.display();
}

// Doesn't do anything yet but will prevent tanks and projectiles from leaving the screen
void Game::clampToScreen()
{
    tanks.at(0).clampToScreen(1280,720);
}

// Short helper function to initialise multiple tanks if necessary
void Game::initialiseTanks(int numTanks)
{
    float speed = 100.0f, xPos = 300.0f, yPos = 500.0f;
    Tank tank(speed, xPos, yPos);
    for(int i = 0;i<numTanks;i++)
    {
        tanks.push_back(tank);
    }
}

void Game::controlTank(int tank_index)
{
    // Movement controls
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        tanks.at(tank_index).move(true,false,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        tanks.at(tank_index).move(false,true,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        tanks.at(tank_index).aimBarrel(true,false,dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        tanks.at(tank_index).aimBarrel(false,true,dt);
    }
    
    float elapsedTime = shootTimer.getElapsedTime().asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)&& elapsedTime >=0.5)
    {
        tanks.at(tank_index).shoot(dt);
        shootTimer.restart();
    }
}