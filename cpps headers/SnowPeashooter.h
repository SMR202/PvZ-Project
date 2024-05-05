#pragma once
#include "Plant.h"

class SnowPeashooter : public Plant {
public:
    SnowPeashooter(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~SnowPeashooter();
};

