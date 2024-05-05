#pragma once
#ifndef BEGINNERSGARDEN_H
#define BEGINNERSGARDEN_H

#include "Levels.h"

class BeginnersGarden : public Levels {
protected:
    BeginnersGarden();

public:
    BeginnersGarden& getInstance();
};

#endif // !BEGINNERSGARDEN_H