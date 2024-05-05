#pragma once
#include "Plant.h"
using namespace std;


class PlantFactory {
protected:
    Plant* plants[MAX_PLANTS];
    int index;
    int numPlants;
public:
    PlantFactory(int lvl = 1);

    Plant*& createPlant(string name, int x, int y);
    Plant*& getPlant(int i);
    void killPlant(int i);
    ~PlantFactory();
};

