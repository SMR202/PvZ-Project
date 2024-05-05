#pragma once
#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"

class Plant; // Forward declaration

class Sunflower : public Plant {
public:
    Sunflower(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~Sunflower();
};



#endif // !SUNFLOWER_H