#include "Game.h"

Game::Game(int windowWidth, int windowHeight, std::string windowName, int numberTanks)
    : window(sf::VideoMode(windowWidth,windowHeight), windowName)
{
    window.setFramerateLimit(60);
    numTanks = numberTanks;
    turnTime.restart();
    shootTimer.restart();
}
Game::~Game()
{
}

// Game functions
void Game::run()
{
    initialiseTanks(numTanks);
    while(window.isOpen())
    {
        pollEvent();
        dt = dtClock.restart().asSeconds();
        totalTime += dt;
        while(totalTime >=frameTime)
        {
            updateFrame();
            totalTime-=frameTime;
        }
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
    for (size_t i = 0; i< tanks.size(); i++)
    {
        for(size_t j = 0; j<tanks.at(i).getBullets()->size(); j++)
        {
            tanks.at(i).getBullets()->at(j).moveBullet(frameTime/numTanks, 0.001);
        }
        if(tanks.at(i).isActive) controlTank(i);
        selectTank();
    }
    //  Temporary code to handle player movement, will change this once the game is properly turn based
    
    clampToScreen();
}

void Game::displayFrame()
{
    window.clear();
    // Drawing stuff to the screen goes here
    
    // Draws every tank, and every bullet of every tank
    window.setView(gameView);
    drawTanksAndBullets();
    
    
    window.setView(hudView);
    drawHUD();
    
    
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
    float speed = 80.0f, xPos = 300.0f, yPos = 500.0f;
    Tank tank(speed, xPos, yPos);
    for(int i = 0;i<numTanks;i++)
    {
        tanks.push_back(tank);
    }
    tanks.at(0).isActive = true;
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

// Switches to next player based on how many shots they have taken
void Game::selectTank()
{
    for (size_t i = 0; i < tanks.size();i++)
    {
        if(tanks.at(i).getShotsTaken() == 5)
        {
            tanks.at(i).isActive = false;
            tanks.at(i).resetShotsTaken();
            if(i+1 < tanks.size())
            {
                tanks.at(i+1).isActive = true;
            } else
                tanks.front().isActive = true;
        }
    }
    
}

void Game::drawHUD()
{
    arialFont.loadFromFile("arial.ttf");
    sf::Text txt("Hello", arialFont);
    txt.setCharacterSize(30);
    txt.setScale(1,2);
    window.draw(txt);
}

void Game::drawTanksAndBullets()
{
    for(auto tank: tanks)
    {
        window.draw(tank.getTank());
        window.draw(tank.getBarrel());
        // Draws bullets, deletes them if they are out of bounds
        for(size_t i = 0; i< (tank.getBullets()->size()); i++)
        {
            sf::Vector2f coords = tank.getBullets()->at(i).getBullet().getPosition();
            bool outOfBounds = coords.x< 0 || coords.x >1280 || coords.y >720;
            window.draw(tank.getBullets()->at(i).getBullet());
            if(outOfBounds)
            {
                tank.getBullets()->erase(tank.getBullets()->begin()+i);
            }
        }
    }
}