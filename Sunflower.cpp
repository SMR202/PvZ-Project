#include "Sunflower.h"

Sunflower::Sunflower(int x, int y) : Plant(300, 0, 100, "sunflower", x, y, 127, 630) {
    plantTexture.loadFromFile("Images/Sunflower.png");
    plantRect = sf::IntRect(0, 0, 133, 150);
    sf::Sprite sunflowerSprite(plantTexture, plantRect);
    sunflowerSprite.setScale(0.5f, 0.5f);
    sunflowerSprite.setPosition(position.x, position.y);
    setSprite(sunflowerSprite);
}

void Sunflower::attack(ZombieFactory& zombies) {
    // Sunflower does not attack
}

Sunflower::~Sunflower() {}

