#pragma once
#ifndef SHOVEL_H
#define SHOVEL_H

#include "Grid.h"

class Shovel {

public:
    Shovel();

    void use(Grid* grid, coordinates& point);
    void use(Grid* grid, int x, int y);
    ~Shovel();
};

#endif // !SHOVEL_H