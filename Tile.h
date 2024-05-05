#pragma once
#ifndef TILE_H
#define TILE_H
#include "Plant.h"
#include "Zombie.h"
#include "Constants.h"
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

#endif // !TILE_H