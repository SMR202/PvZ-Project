#pragma once
#include <SFML/Graphics.hpp>
#include "PlantFactory.h"

class Zombie {
protected:
    int health, damage;
    double speed;
    std::string name;
    sf::Clock moveClock;
    sf::Clock animationClock;
    coordinates position;
    sf::Texture zombieTexture;
    sf::IntRect zombieRect;
    sf::Sprite zombieSprite;

public:
    Zombie(int health = 100, int damage = 5, float speed = 1.0, std::string name = "plant", int x = 0, int y = 0);
    virtual ~Zombie();

    virtual void attack(PlantFactory& plants);
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
    void setSprite(sf::Sprite& zombiesprite);
    sf::Clock& getAnimationClock();
};

