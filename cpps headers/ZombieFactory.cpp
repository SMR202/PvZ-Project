#include "ZombieFactory.h"

ZombieFactory::ZombieFactory() : zombiesCount(0) {
    for (int i = 0; i < MAX_ZOMBIES; ++i) {
        this->zombies[i] = nullptr;
    }
}

void ZombieFactory::createZombie(std::string name, int x, int y) {
    int randRow[5] = { 20, 85, 160, 225, 295 }; // [0, 1, 2, 3, 4]
    y = randRow[rand() % 5];
    if (zombies[zombiesCount] == nullptr && creationClock.getElapsedTime().asSeconds() > 4) {
        zombies[zombiesCount] = new SimpleZombie(x, y);
        zombies[zombiesCount]->setPosition(x, y);
        zombies[zombiesCount]->setName(name);
        zombiesCount++;
        creationClock.restart();
    }
}

Zombie*& ZombieFactory::getZombie(int i) {
    return zombies[i];
}

void ZombieFactory::killZombie(int i) {
    delete zombies[i];
    zombies[i] = nullptr;
}

sf::Clock& ZombieFactory::getClock() {
    return creationClock;
}

ZombieFactory::~ZombieFactory() {
    for (int i = 0; i < MAX_ZOMBIES; i++) {
        if (zombies[i] != nullptr)
            delete this->zombies[i];
    }
}
