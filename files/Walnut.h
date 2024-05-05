#pragma once
#ifndef WALNUT_H
#define WALNUT_H
#include "Plant.h"

class Plant; // Forward declaration
class ZombieFactory; // Forward declaration

class Walnut : public Plant {
public:
    Walnut(int x = 0, int y = 0);

    virtual void attack(ZombieFactory& zombies) override;
    virtual ~Walnut();
};

#endif // !WALNUT_H