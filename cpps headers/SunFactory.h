#pragma once
#include "Sun.h"
#include <SFML/System/Clock.hpp>

class SunFactory {
protected:
    Sun* suns[15];
    int totalSun;
    sf::Clock clock;

public:
    SunFactory(int totalSun = 50);

    void generateSun(int i = 0, int x = rand() % 710 + 180, int y = 0);
    Sun*& getSun(int i);
    void collectSun(int x = 0, int y = 0);
    ~SunFactory();
};

