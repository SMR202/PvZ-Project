#include "Tile.h"

Tile::Tile(Plant* plant, Zombie* zombies[MAX_ZOMBIES_PER_TILE]) : plant(plant) {
    for (int i = 0; i < MAX_ZOMBIES_PER_TILE; ++i) {
        this->zombies[i] = nullptr;
    }
}

void Tile::addPlant(Plant* plant) {
    if (plant != nullptr) {
        this->plant = plant;
    }
}

void Tile::removePlant() {
    this->plant = nullptr;
}

Plant*& Tile::getPlant() {
    return plant;
}
