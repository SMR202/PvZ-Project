#include "Zombie.h"
#include <iostream>
using namespace std;

Zombie::Zombie(int health, int damage, float speed, std::string name, int x, int y)
    : health(health), damage(damage), speed(speed), name(name), moveClock(), animationClock(), position({ x, y }) {}

Zombie::~Zombie() {}

void Zombie::attack(PlantFactory& plants, Grid& grid) {
    for (int i = 0; i < MAX_ZOMBIES; i++) {
        if (plants.getPlant(i) != nullptr) {
            if (plants.getPlant(i)->getPosition().x >= position.x &&
                plants.getPlant(i)->getPosition().x <= position.x + getRect().width &&
                plants.getPlant(i)->getPosition().y + plants.getPlant(i)->getRect().height >= position.y &&
                plants.getPlant(i)->getPosition().y <= position.y + getRect().height) {
                // Collision detected, apply damage to the plant
                plants.getPlant(i)->setHealth(plants.getPlant(i)->getHealth() - damage);
                if (plants.getPlant(i)->getHealth() <= 0) {
                    // Plant destroyed, remove it from the plant factory
                    plants.killPlant(i, grid);
                    cout << "killed";
                }
            }
        }
    }
}

int Zombie::getHealth() {
    return health;
}

void Zombie::setHealth(int health) {
    this->health = health;
}

int Zombie::getDamage() {
    return damage;
}

void Zombie::setDamage(int damage) {
    this->damage = damage;
}

double Zombie::getSpeed() {
    return speed;
}

void Zombie::setSpeed(double speed) {
    this->speed = speed;
}

coordinates& Zombie::getPosition() {
    return position;
}

void Zombie::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

std::string Zombie::getName() {
    return name;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::move() {
    if (moveClock.getElapsedTime().asSeconds() >= 0.05) {
        position.x = zombieSprite.getPosition().x - speed;
        position.y = zombieSprite.getPosition().y;
        zombieSprite.setPosition(position.x, position.y);
        moveClock.restart();
    }
}

void Zombie::stop() {
    if (shouldStop && stopClock.getElapsedTime().asSeconds() >= 1) {
        shouldStop = false;
        stopClock.restart();
    }
}

void Zombie::startStop() {
	shouldStop = true;
}

sf::Sprite& Zombie::getSprite() {
    return zombieSprite;
}

sf::IntRect& Zombie::getRect() {
    return zombieRect;
}

void Zombie::setSprite(sf::Sprite& zombiesprite) {
    zombieSprite = zombiesprite;
}

sf::Clock& Zombie::getAnimationClock() {
    return animationClock;
}
