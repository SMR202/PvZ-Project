#pragma once
#include "Plant.h"
#include "Zombie.h"

class Tile {
protected:
    Plant* plant;
    Zombie* zombies[MAX_ZOMBIES_PER_TILE];

public:
    Tile(Plant* plant = nullptr, Zombie* zombies[MAX_ZOMBIES_PER_TILE] = { nullptr });

    void addPlant(Plant* plant);
    void removePlant();
    Plant*& getPlant();
};

