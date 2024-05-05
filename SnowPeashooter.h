#pragma once
#ifndef SNOWPEASHOOTER_H
#define SNOWPEASHOOTER_H
#include "Plant.h"

class Plant; // Forward declaration
class ZombieFactory; // Forward declaration

class SnowPeashooter : public Plant {
public:
    SnowPeashooter(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~SnowPeashooter();
};

#endif // !SNOWPEASHOOTER_H