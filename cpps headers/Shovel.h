#pragma once
#include "Grid.h"

class Shovel {

public:
    Shovel();

    void use(Grid* grid, coordinates& point);
    void use(Grid* grid, int x, int y);
    ~Shovel();
};
