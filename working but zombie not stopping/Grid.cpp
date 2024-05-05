#include "Grid.h"

Grid::Grid() : lastLineDefence(nullptr) {}

Tile& Grid::getTile(int x, int y) {
    return tiles[x][y];
}

Tile& Grid::getTile(coordinates& point) {
    return tiles[point.x][point.y];
}