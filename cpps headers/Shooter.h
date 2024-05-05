#pragma once
#include "Plant.h"

class Shooter : public Plant {
protected:
    coordinates bulletPosition;
    sf::Texture bulletTexture;
    sf::IntRect bulletRect;
    sf::Sprite bulletSprite;
    sf::Clock bulletClock;

public:
    Shooter(int health = 100, int damage = 5, int cost = 100, std::string name = "shooter", int x = 0, int y = 0, int incrementX = 0, int limitX = 0);

    virtual void attack(ZombieFactory& zombies);
    void setSprite(sf::Sprite& bulletsprite);
    void setBulletPosition(int x, int y);
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    virtual void drawPlant(sf::RenderWindow& window);
    virtual ~Shooter();
};

