#include "Levels.h"

Levels::Levels(int num) : plantFactory(), zombieFactory(), time(), num(num), name(), description(), objectives(), challenges(), rewards(), wave(), shovel(), sunFactory() {}

Levels::~Levels() {}

PlantFactory& Levels::getPlantFactory() {
    return plantFactory;
}

ZombieFactory& Levels::getZombieFactory() {
    return zombieFactory;
}

SunFactory& Levels::getSunFactory() {
    return sunFactory;
}