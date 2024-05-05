#pragma once
#include "Plant.h"
#include "ZombieFactory.h"

class RepeaterShooter : public Plant {
public:
    RepeaterShooter(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~RepeaterShooter();
};

