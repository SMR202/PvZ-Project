#pragma once
#ifndef SHOVEL_H
#define SHOVEL_H

#include "Grid.h"

class Shovel {
private:
    int positionX;
    int positionY;
public:
    Shovel();
    void use(Grid& grid, coordinates& point, PlantFactory& plants);
    ~Shovel();
};

#endif // !SHOVEL_H