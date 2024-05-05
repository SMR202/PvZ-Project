#include "Shooter.h"

Shooter::Shooter(int health, int damage, int cost, std::string name, int x, int y, int incrementX, int limitX)
    : Plant(health, damage, cost, name, x, y, incrementX, limitX) {
    bulletPosition.x = x;
    bulletPosition.y = y;
}

void Shooter::attack(ZombieFactory& zombies) {
    if (bulletSprite.getPosition().x >= 800) {
        bulletSprite.setPosition(position.x + 5, position.y);
    }
    if (bulletClock.getElapsedTime().asSeconds() >= 0.005) {
        bulletPosition.x = bulletSprite.getPosition().x + 2;
        bulletPosition.y = bulletSprite.getPosition().y;
        bulletSprite.setPosition(bulletPosition.x, bulletPosition.y);
        bulletClock.restart();
    }
    for (int i = 0; i < MAX_ZOMBIES; i++) {
        if (zombies.getZombie(i) != nullptr) {
            if (bulletPosition.x + bulletRect.width >= zombies.getZombie(i)->getPosition().x && bulletPosition.x <= zombies.getZombie(i)->getPosition().x + zombies.getZombie(i)->getRect().width && bulletPosition.y + bulletRect.height >= zombies.getZombie(i)->getPosition().y && bulletPosition.y <= zombies.getZombie(i)->getPosition().y + zombies.getZombie(i)->getRect().height) {
                // Collision detected, apply damage to the zombie
                zombies.getZombie(i)->setHealth(zombies.getZombie(i)->getHealth() - damage);
                if (zombies.getZombie(i)->getHealth() <= 0) {
                    zombies.killZombie(i);
                }
                bulletSprite.setPosition(position.x + 5, position.y);
            }
        }
    }
}

void Shooter::setSprite(sf::Sprite& bulletsprite) {
    this->bulletSprite = bulletsprite;
}

void Shooter::setBulletPosition(int x, int y) {
    bulletPosition.x = x;
    bulletPosition.y = y;
}

sf::Sprite& Shooter::getSprite() {
    return bulletSprite;
}

sf::IntRect& Shooter::getRect() {
    return bulletRect;
}

void Shooter::drawPlant(sf::RenderWindow& window) {
    window.draw(plantSprite);
    window.draw(bulletSprite);
}

Shooter::~Shooter() {}
