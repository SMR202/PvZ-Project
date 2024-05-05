#include "SunFactory.h"

SunFactory::SunFactory(int totalSun) : totalSun(totalSun), clock() {
    for (int i = 0; i < 15; i++) {
        suns[i] = nullptr;
    }
}

void SunFactory::generateSun(int i, int x, int y) {
    if (clock.getElapsedTime().asSeconds() >= 4) {
        suns[i] = new Sun();
        suns[i]->getSprite().setPosition(x, y);
        clock.restart();
    }
}

Sun*& SunFactory::getSun(int i) {
    return suns[i];
}

void SunFactory::collectSun(int x, int y) {
    totalSun += 25;
    for (int i = 0; i < 15; i++) {
        if (suns[i] != nullptr) {
            delete suns[i];
            suns[i] = nullptr;
        }
    }
}

SunFactory::~SunFactory() {
    for (int i = 0; i < 15; i++) {
        if (suns[i] != nullptr)
            delete this->suns[i];
    }
}
