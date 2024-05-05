#pragma once
#include "Tile.h"
#include "LastLineDefence.h"
#include "coordinates.h"

class Grid {
protected:
    Tile tiles[ROWS][COLS];
    LastLineDefence* lastLineDefence;

public:
    Grid();

    Tile& getTile(int x, int y);
    Tile& getTile(coordinates& point);
};

