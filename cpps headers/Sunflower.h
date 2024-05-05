#pragma once
#include "Plant.h"

class Sunflower : public Plant {
public:
    Sunflower(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~Sunflower();
};

