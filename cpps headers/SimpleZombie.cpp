#include "SimpleZombie.h"

SimpleZombie::SimpleZombie(int x, int y) : Zombie(300, 20, 5, "simpleZombie", x, y) {
    zombieTexture.loadFromFile("Images/simpleZombie.png");
    zombieRect = sf::IntRect(0, 0, 80, 100);
    sf::Sprite sprite(zombieTexture, zombieRect);
    sprite.setPosition(position.x, position.y);
    setSprite(sprite);
}

SimpleZombie::~SimpleZombie() {}
