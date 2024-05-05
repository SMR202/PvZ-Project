#include "SnowPeashooter.h"

SnowPeashooter::SnowPeashooter(int x, int y) : Plant(300, 20, 175, "snowpeashooter", x, y, 124, 840) {
    plantTexture.loadFromFile("Images/SnowPea.png");
    plantRect = sf::IntRect(0, 0, 127, 131);
    sf::Sprite snowPeaShooterSprite(plantTexture, plantRect);
    snowPeaShooterSprite.setScale(0.5f, 0.5f);
    snowPeaShooterSprite.setPosition(position.x, position.y);
    setSprite(snowPeaShooterSprite);
}

void SnowPeashooter::attack(ZombieFactory& zombies) {
    // SnowPeashooter does not attack
}

SnowPeashooter::~SnowPeashooter() {}
