#include "Walnut.h"

Walnut::Walnut(int x, int y) : Plant(4000, 0, 50, "walnut", x, y, 111, 440) {
    plantTexture.loadFromFile("Images/Walnut.png");
    plantRect = sf::IntRect(0, 0, 108, 130);
    sf::Sprite walnutSprite(plantTexture, plantRect);
    walnutSprite.setScale(0.5f, 0.5f);
    walnutSprite.setPosition(position.x, position.y);
    setSprite(walnutSprite);
}

void Walnut::attack(ZombieFactory& zombies) {
    // Walnut does not attack
}

Walnut::~Walnut() {}
