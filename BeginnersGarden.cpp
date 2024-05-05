#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() : Levels(1) {}

BeginnersGarden& BeginnersGarden::getInstance() {
    BeginnersGarden instance;
    return instance;
}
