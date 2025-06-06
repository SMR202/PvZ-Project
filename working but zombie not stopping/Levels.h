#pragma once
#ifndef LEVELS_H
#define LEVELS_H

#include "PlantFactory.h"
#include "ZombieFactory.h"
#include "SunFactory.h"
#include "Waves.h"
#include "Shovel.h"
#include "Times.h"


class Levels {
protected:
    PlantFactory plantFactory;
    ZombieFactory zombieFactory;
    SunFactory sunFactory;
    Times time;
    int num;
    string name;
    string description;
    string objectives;
    string challenges;
    string rewards;
    string zombies[MAX_ZOMBIES];
    Waves wave;
    Shovel shovel;

public:
    Levels(int num = 1);
    virtual ~Levels();

    PlantFactory& getPlantFactory();
    ZombieFactory& getZombieFactory();
    SunFactory& getSunFactory();
};

#endif // !LEVELS_H