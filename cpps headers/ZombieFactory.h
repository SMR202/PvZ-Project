#pragma once
#include "SimpleZombie.h"
#include <SFML/System/Clock.hpp>

class ZombieFactory {
protected:
    Zombie* zombies[MAX_ZOMBIES];
    sf::Clock creationClock;
    int zombiesCount;

public:
    ZombieFactory();

    void createZombie(std::string name = "", int x = 720, int y = 295);
    Zombie*& getZombie(int i);
    void killZombie(int i);
    sf::Clock& getClock();
    ~ZombieFactory();
};

