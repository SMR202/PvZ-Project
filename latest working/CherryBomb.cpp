#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y) : Plant(300, 500, 150, "cherrybomb", x, y, 331, 3975) {
    plantTexture.loadFromFile("Images/cherryBomb.png");
    plantRect = sf::IntRect(0, 0, 331, 233);
    sf::Sprite cherryBombSprite(plantTexture, plantRect);
    cherryBombSprite.setScale(0.5f, 0.5f);
    cherryBombSprite.setPosition(position.x, position.y);
    setSprite(cherryBombSprite);
}

void CherryBomb::attack(ZombieFactory& zombies) {
    // CherryBomb does not attack
}

CherryBomb::~CherryBomb() {}
