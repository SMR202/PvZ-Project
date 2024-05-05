#include "Peashooter.h"

Peashooter::Peashooter(int x, int y) : Shooter(300, 300, 100, "peashooter", x, y, 108, 756) {
    plantTexture.loadFromFile("Images/Peashooter.png");
    plantRect = sf::IntRect(0, 0, 108, 130);
    sf::Sprite peaShooterSprite(plantTexture, plantRect);
    peaShooterSprite.setScale(0.5f, 0.5f);
    peaShooterSprite.setPosition(position.x, position.y);
    Plant::setSprite(peaShooterSprite);

    bulletTexture.loadFromFile("Images/pea_projectile.png");
    bulletRect = sf::IntRect(0, 0, 24, 24);
    sf::Sprite peaBulletSprite(bulletTexture, bulletRect);
    peaBulletSprite.setPosition(position.x + 5, position.y);
    Shooter::setSprite(peaBulletSprite);
}

Peashooter::~Peashooter() {}
