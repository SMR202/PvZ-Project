#include "Shovel.h"
#include <iostream>
using namespace std;

Shovel::Shovel() : positionX(400), positionY(13) {}

void Shovel::use(Grid& grid, coordinates& point, PlantFactory& plants) {
    for (int i = 0; i < MAX_PLANTS; i++) {
        cout << "step 1";
        if (plants.getPlant(i) != nullptr) {
            cout << "step 2";
                cout << "step 3";
                // Collision detected, remove the plant
                plants.getPlant(i)->setHealth(plants.getPlant(i)->getHealth() - 250);
                plants.killPlant(i, grid);
                cout << "removed";
  
        }
    }
}

Shovel::~Shovel() {}
