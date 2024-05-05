#pragma once
#ifndef SUN_H
#define SUN_H
#include <SFML/Graphics.hpp>

class Sun {
private:
    sf::Clock moveClock;
    sf::Texture sunTexture;
    sf::IntRect sunRect;
    sf::Sprite sunSprite;

public:
    Sun();
    void moveSun();
    sf::Sprite& getSprite();
    sf::IntRect& getRect();
    void setSprite(sf::Sprite& sunsprite);
};

#endif // !SUN_H