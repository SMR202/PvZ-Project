#include "RepeaterShooter.h"

RepeaterShooter::RepeaterShooter(int x, int y) : Plant(300, 20, 175, "repeatershooter", x, y, 159, 597) {
    plantTexture.loadFromFile("Images/Repeater.png");
    plantRect = sf::IntRect(0, 0, 159, 157);
    sf::Sprite repeaterShooterSprite(plantTexture, plantRect);
    repeaterShooterSprite.setScale(0.5f, 0.5f);
    repeaterShooterSprite.setPosition(position.x, position.y);
    setSprite(repeaterShooterSprite);
}

void RepeaterShooter::attack(ZombieFactory& zombies) {
    // RepeaterShooter does not attack
}

RepeaterShooter::~RepeaterShooter() {}
