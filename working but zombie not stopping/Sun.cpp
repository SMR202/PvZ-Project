#include "Sun.h"

Sun::Sun() : moveClock() {
    sunTexture.loadFromFile("Images/sun.png");
    sunRect = sf::IntRect(0, 0, 250, 250);
    sunSprite.setTexture(sunTexture);
    sunSprite.setTextureRect(sunRect);
    sunSprite.setScale(0.22f, 0.22f);
    sunSprite.setPosition(200, 0);
    sunSprite.setOrigin(sunSprite.getLocalBounds().width / 2, sunSprite.getLocalBounds().height / 2);
}

void Sun::moveSun() {
    if (sunSprite.getPosition().y < 450 && moveClock.getElapsedTime().asSeconds() >= 0.04) {
        sunSprite.move(0, 2);
        sunSprite.rotate(2);
        moveClock.restart();
    }
}

sf::Sprite& Sun::getSprite() {
    return sunSprite;
}

sf::IntRect& Sun::getRect() {
    return sunRect;
}

void Sun::setSprite(sf::Sprite& sunsprite) {
    this->sunSprite = sunsprite;
}