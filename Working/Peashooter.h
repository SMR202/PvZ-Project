#pragma once
#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include "Shooter.h"

class Peashooter : public Shooter {
public:
    Peashooter(int x = 0, int y = 0);

    virtual ~Peashooter();
};

#endif // PEASHOOTER_H