#pragma once
#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "Plant.h"
#include "ZombieFactory.h"

class CherryBomb : public Plant {
public:
    CherryBomb(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~CherryBomb();
};

#endif // !CHERRYBOMB_H