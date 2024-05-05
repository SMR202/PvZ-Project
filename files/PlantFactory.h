#pragma once
#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"
#include "Sunflower.h"
#include "Peashooter.h"
#include "Walnut.h"
#include "CherryBomb.h"
#include "SnowPeashooter.h"
#include "Repeatershooter.h"

#include "Constants.h"
using namespace std;

class Plant;

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

#endif // !PLANTFACTORY_H