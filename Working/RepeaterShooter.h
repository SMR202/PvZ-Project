#pragma once
#ifndef REPEATER_SHOOTER_H
#define REPEATER_SHOOTER_H

#include "Plant.h"
#include "ZombieFactory.h"

class Plant; // Forward declaration
class ZombieFactory; // Forward declaration

class RepeaterShooter : public Plant {
public:
    RepeaterShooter(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~RepeaterShooter();
};

#endif // REPEATER_SHOOTER_H