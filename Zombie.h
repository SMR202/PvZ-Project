#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include "PlantFactory.h"
#include "coordinates.h"

class Grid;

class Zombie {
protected:
    int health, damage;
    double speed;
    std::string name;
    sf::Clock stopClock;
    sf::Clock moveClock;
    sf::Clock animationClock;
    coordinates position;
    sf::Texture zombieTexture;
    sf::IntRect zombieRect;
    sf::Sprite zombieSprite;
    bool shouldStop = false;  // Add this line

public:
    Zombie(int health = 100, int damage = 5, float speed = 1.0, std::string name = "plant", int x = 0, int y = 0);
    virtual ~Zombie();

    virtual void attack(class PlantFactory& plants, Grid& grid); // Fixed the syntax error

    int getHealth();
    void setHealth(int health);
    int getDamage();
    void setDamage(int damage);
    double getSpeed();
    void setSpeed(double speed);
    coordinates& getPosition();
    void setPosition(int x, int y);
    std::string getName();
    void setName(std::string name);
    void move();
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    void stop();
    void startStop();
    void setSprite(sf::Sprite& zombiesprite);
    sf::Clock& getAnimationClock();
};

#endif // ZOMBIE_H