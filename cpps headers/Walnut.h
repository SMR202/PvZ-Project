#pragma once
#include "Plant.h"

class Walnut : public Plant {
public:
    Walnut(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~Walnut();
};

