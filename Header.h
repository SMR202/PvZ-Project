#pragma once
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <string>
using namespace sf;
using namespace std;

const int MAX_PLANTS = 6;
const int MAX_ZOMBIES = 5;
const int MAX_ZOMBIES_PER_TILE = 10;
const int ROWS = 5;
const int COLS = 9;

struct coordinates;
class Game;
class Scoreboard;
class State;
class Levels;
class PlantFactory;
class ZombieFactory;
class Times;
class Zombie;
class Tile;
class Grid;
class LastLineDefence;
class Shovel;
class Waves;

struct coordinates {
	int x;
	int y;
};

class Sun {
protected:

	Clock moveClock;
	sf::Texture sunTexture;
	sf::IntRect sunRect;
	sf::Sprite sunSprite;
public:
	Sun() : moveClock() {
		sunTexture.loadFromFile("Images/sun.png");
		sunRect = sf::IntRect(0, 0, 250, 250);
		sf::Sprite sunSprite(sunTexture, sunRect);
		sunSprite.setScale(0.22f, 0.22f);
		sunSprite.setPosition(200, 0);
		sunSprite.setOrigin(sunSprite.getLocalBounds().width / 2, sunSprite.getLocalBounds().height / 2);
		setSprite(sunSprite);
	}
	void moveSun() {
		if (sunSprite.getPosition().y < 450 && moveClock.getElapsedTime().asSeconds() >= 0.04) {
			sunSprite.move(0, 2);
			sunSprite.rotate(2);
			moveClock.restart();
		}
	}
	Sprite& getSprite() {
		return sunSprite;
	}
	IntRect& getRect() {
		return sunRect;
	}
	void setSprite(Sprite& sunsprite) {
		this->sunSprite = sunsprite;
	}

};

class Plant {
protected:
	int health, damage, cost, incrementX, limitX;
	string name;
	coordinates position;
	Clock clock;
	bool isReady;
	bool isPressed;
	sf::Texture plantTexture;
	sf::IntRect plantRect;
	sf::Sprite plantSprite;
public:
	Plant(int health = 100, int damage = 5, int cost = 100, string name = "plant", int x = 0, int y = 0, int incrementX = 0, int limitX = 0) : health(health), damage(damage), cost(cost), isReady(false), isPressed(false), incrementX(incrementX), limitX(limitX) {
		position.x = x;
		position.y = y;
	}
	Clock& getClock() {
		return clock;
	}
	int getIncrementX() {
		return incrementX;
	}
	int getlimitX() {
		return limitX;
	}
	void setIncrementX(int incrementX) {
		this->incrementX = incrementX;
	}
	void setLimitX(int limitX) {
		this->limitX = limitX;
	}
	virtual void attack(Zombie* target) = 0;
	int getHealth() {
		return health;
	}
	void restartClock() {
		clock.restart();
	}
	float getElapsedTime() {
		Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() >= 5) {
			isReady = true;
		}
		return elapsed.asSeconds();
	}
	bool getIsReady() {
		return isReady;
	}
	void setIsReady(bool ready) {
		isReady = ready;
	}
	int getCost() {
		return cost;
	}
	int getDamage() {
		return damage;
	}
	coordinates getPosition() {
		return position;
	}
	void setPosition(int x, int y) {
		position.x = x;
		position.y = y;
	}
	bool getPressed() {
		isPressed = true;
		return isPressed;
	}
	void setPressed(bool pressed) {
		isPressed = pressed;
	}
	Sprite& getSprite() {
		return plantSprite;
	}
	IntRect& getRect() {
		return plantRect;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setSprite(Sprite& plantsprite) {
		this->plantSprite = plantsprite;
	}
	virtual ~Plant() {}
};

class Peashooter : public Plant {
public:
	Peashooter(int x = 0, int y = 0) : Plant(300, 20, 100, "peashooter", x, y, 108, 756) {
		plantTexture.loadFromFile("Images/Peashooter.png");
		plantRect = sf::IntRect(0, 0, 108, 130);
		sf::Sprite peaShooterSprite(plantTexture, plantRect);
		peaShooterSprite.setScale(0.5f, 0.5f);
		peaShooterSprite.setPosition(position.x, position.y);
		setSprite(peaShooterSprite);
	}

	virtual void attack(Zombie* target) {}

	virtual ~Peashooter() {}

};

class SnowPeashooter : public Plant {
public:
	SnowPeashooter(int x = 0, int y = 0) : Plant(300, 20, 175, "snowpeashooter", x, y, 124, 840) {
		plantTexture.loadFromFile("Images/SnowPea.png");
		plantRect = sf::IntRect(0, 0, 127, 131);
		sf::Sprite snowPeaShooterSprite(plantTexture, plantRect);
		snowPeaShooterSprite.setScale(0.5f, 0.5f);
		snowPeaShooterSprite.setPosition(position.x, position.y);
		setSprite(snowPeaShooterSprite);

	}

	virtual void attack(Zombie* target) {}

	virtual ~SnowPeashooter() {}

};

class RepeaterShooter : public Plant {
public:
	RepeaterShooter(int x = 0, int y = 0) : Plant(300, 20, 175, "repeatershooter", x, y, 159, 597) {
		plantTexture.loadFromFile("Images/Repeater.png");
		plantRect = sf::IntRect(0, 0, 159, 157);
		sf::Sprite repeaterShooterSprite(plantTexture, plantRect);
		repeaterShooterSprite.setScale(0.5f, 0.5f);
		repeaterShooterSprite.setPosition(position.x, position.y);
		setSprite(repeaterShooterSprite);

	}

	virtual void attack(Zombie* target) {}

	virtual ~RepeaterShooter() {}

};

class Walnut : public Plant {
public:
	Walnut(int x = 0, int y = 0) : Plant(4000, 0, 50, "walnut", x, y, 111, 440) {
		plantTexture.loadFromFile("Images/Walnut.png");
		plantRect = sf::IntRect(0, 0, 108, 130);
		sf::Sprite walnutSprite(plantTexture, plantRect);
		walnutSprite.setScale(0.5f, 0.5f);
		walnutSprite.setPosition(position.x, position.y);
		setSprite(walnutSprite);

	}

	virtual void attack(Zombie* target) {}

	virtual ~Walnut() {}

};

class Sunflower : public Plant {
public:
	Sunflower(int x = 0, int y = 0) : Plant(300, 0, 100, "sunflower", x, y, 127, 630) {
		plantTexture.loadFromFile("Images/Sunflower.png");
		plantRect = sf::IntRect(0, 0, 133, 150);
		sf::Sprite sunflowerSprite(plantTexture, plantRect);
		sunflowerSprite.setScale(0.5f, 0.5f);
		sunflowerSprite.setPosition(position.x, position.y);
		setSprite(sunflowerSprite);

	}

	virtual void attack(Zombie* target) {}

	virtual ~Sunflower() {}

};

class CherryBomb : public Plant {
public:
	CherryBomb(int x = 0, int y = 0) : Plant(300, 500, 150, "cherrybomb", x, y, 331, 3975) {
		plantTexture.loadFromFile("Images/cherryBomb.png");
		plantRect = sf::IntRect(0, 0, 331, 233);
		sf::Sprite cherryBombSprite(plantTexture, plantRect);
		cherryBombSprite.setScale(0.5f, 0.5f);
		cherryBombSprite.setPosition(position.x, position.y);
		setSprite(cherryBombSprite);

	}

	virtual void attack(Zombie* target) {}

	virtual ~CherryBomb() {}

};

class Zombie {
protected:
	int health, damage;
	double speed;
	string name;
	Clock clock;
	coordinates position;
	sf::Texture zombieTexture;
	sf::IntRect zombieRect;
	sf::Sprite zombieSprite;

public:
	Zombie(int health = 100, int damage = 5, float speed = 1.0, string name = "plant", int x = 0, int y = 0) : health(health), damage(damage), speed(speed), clock() {
		position.x = x;
		position.y = y;
	}
	virtual void attack(Plant* target) = 0;
	int getHealth() {
		return health;
	}
	void setHealth(int health) {
		this->health = health;
	}
	int getDamage() {
		return damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	double getSpeed() {
		return speed;
	}
	void setSpeed(double speed) {
		this->speed = speed;
	}
	coordinates getPosition() {
		return position;
	}
	void setPosition(int x, int y) {
		position.x = x;
		position.y = y;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	void move() {
		if (clock.getElapsedTime().asSeconds() >= 0.05) {
			zombieSprite.move(-speed, 0);
			clock.restart();

		}
	}
	Sprite& getSprite() {
		return zombieSprite;
	}
	IntRect& getRect() {
		return zombieRect;
	}
	void setSprite(Sprite& zombiesprite) {
		this->zombieSprite = zombiesprite;
	}
	virtual ~Zombie() {}

};

class SimpleZombie : public Zombie {
public:
SimpleZombie(int x = 720, int y = 230) : Zombie(300, 20, 5, "simpleZombie", x, y) {
	zombieTexture.loadFromFile("Images/simpleZombie.png");
	zombieRect = sf::IntRect(0, 0, 80, 100);
	sf::Sprite sprite(zombieTexture, zombieRect);
	//sprite.setScale(0.5f, 0.5f);
	sprite.setPosition(position.x, position.y);
	setSprite(sprite);
}
	virtual void attack(Plant* target) {}
	virtual ~SimpleZombie() {}
};

class Tile {
protected:
	Plant* plant;
	Zombie* zombies[MAX_ZOMBIES_PER_TILE];
public:
	Tile(Plant* plant = nullptr, Zombie* zombies[MAX_ZOMBIES_PER_TILE] = { nullptr }) : plant(plant) {
		for (int i = 0; i < MAX_ZOMBIES_PER_TILE; ++i) {
			this->zombies[i] = nullptr;
		}
	}
	void addPlant(Plant* plant) {
		if (plant != nullptr) {
			this->plant = plant;
		}
	}
	void removePlant() {
		this->plant = nullptr;
	}
	Plant*& getPlant() {
		return plant;
	}
};

class Grid {
protected:
	Tile tiles[ROWS][COLS];
	LastLineDefence* lastLineDefence;
public:
	Grid() : tiles(), lastLineDefence(nullptr) {}
	Tile& getTile(int x, int y) {
		return tiles[x][y];
	}
	Tile& getTile(coordinates& point) {
		return tiles[point.x][point.y];
	}
};

class LastLineDefence {
protected:
	bool lawnMowers[ROWS];
	bool poolCleaners[ROWS];
	bool roofCleaners[ROWS];
public:
	LastLineDefence() {
		for (int i = 0; i < ROWS; i++) {
			lawnMowers[i] = false;
			poolCleaners[i] = false;
			roofCleaners[i] = false;
		}
	}
};

class Shovel {

public:
	Shovel() {}
	void use(Grid* grid, coordinates& point) {
		//calls remove plant on the passed coordinates in grid

	}
	void use(Grid* grid, int x, int y) {
		//calls remove plant on the passed coordinates in grid
	}
	~Shovel() {}
};

class Waves {
protected:
	int totalWaves;
	int waveNumber;
public:
	Waves(int waveNumber = 1, int totalWaves = 2) : waveNumber(waveNumber), totalWaves(totalWaves) {}
	void startNextWave() {
		//implement logic
	}
	int getCurrentWave() {
		return waveNumber;
	}
	int getTotalWaves() {
		return totalWaves;
	}
	void setCurrentWave(int newWave) {
		waveNumber = newWave;
	}
	void setTotalWave(int newTotalWaves) {
		totalWaves = newTotalWaves;
	}
	~Waves() {}
};

class PlantFactory {
protected:
	Plant* plants[MAX_PLANTS];
	int index;
	int numPlants;
public:
	PlantFactory(int lvl = 1) {
		for (int i = 0; i < MAX_PLANTS; i++) {
			this->plants[i] = nullptr;
		}
	}
	Plant*& createPlant(string name, int x, int y) {
		Plant* newPlant = nullptr;
		if (name == "peaShooter") {
			newPlant = new Peashooter(x, y);
		}
		else if (name == "sunflower") {
			newPlant = new Sunflower(x, y);
		}
		else if (name == "snowPeaShooter") {
			newPlant = new SnowPeashooter(x, y);
		}
		else if (name == "repeaterShooter") {
			newPlant = new RepeaterShooter(x, y);
		}
		else if (name == "walnut") {
			newPlant = new Walnut(x, y);
		}
		else if (name == "cherryBomb") {
			newPlant = new CherryBomb(x, y);
		}
		if (newPlant != nullptr) {
			plants[numPlants++] = newPlant;
		}
		return newPlant;
	}
	/*Plant*& createPlant(string name, int x, int y) {
		int i = 0;
		if (plants[i] != nullptr) {
			plants[i]->setPosition(x,y);
			plants[i]->setName(name);
		}
		return plants[i];
	}*/
	~PlantFactory() {
		for (int i = 0; i < MAX_PLANTS; i++) {
			if (plants[i] != nullptr)
				delete this->plants[i];
		}
	}
	Plant*& getPlant(int i) {
		return plants[i];
	}
};

class ZombieFactory {
protected:
	Zombie* zombies[MAX_ZOMBIES];
public:
	ZombieFactory() {
		for (int i = 0; i < MAX_ZOMBIES; ++i) {
			this->zombies[i] = nullptr;
		}
		zombies[0] = new SimpleZombie();
	}
	Zombie*& createZombie(string name, int x = 720, int y = 230) {
		int i = 0;
		if (zombies[i] != nullptr) {
			zombies[i]->setPosition(x, y);
			zombies[i]->setName(name);
		}
		return zombies[i];
	}
	Zombie*& getZombie(int i) {
		return zombies[i];
	}
	~ZombieFactory() {
		for (int i = 0; i < MAX_ZOMBIES; i++) {
			if (zombies[i] != nullptr)
				delete this->zombies[i];
		}
	}
};

class SunFactory {
protected:
	Sun* suns[15];
	int totalSun;
	Clock clock;
public:
	SunFactory(int totalSun = 50) : totalSun(totalSun), clock() {
		for (int i = 0; i < 15; i++) {
			suns[i] = nullptr;
		}
	}
	void generateSun(int i = 0, int x = rand() % 710 + 180, int y = 0) {
		if (clock.getElapsedTime().asSeconds() >= 4) {
			suns[i] = new Sun();
			suns[i]->getSprite().setPosition(x, y);
			clock.restart();
		}
	}
	Sun*& getSun(int i) {
		return suns[i];
	}
	void collectSun(int x = 0, int y = 0){
		totalSun += 25;
		for (int i = 0; i < 15; i++) {
			if (suns[i] != nullptr) {
				delete suns[i];
				suns[i] = nullptr;
			}
		}
	}

	~SunFactory() {
		for (int i = 0; i < 15; i++) {
			if (suns[i] != nullptr)
				delete this->suns[i];
		}
	}
};

class Times {
protected:

};


class State {
protected:

};


class Levels {
protected:
	PlantFactory plantFactory;
	ZombieFactory zombieFactory;
	SunFactory sunFactory;
	Times time;
	int num;
	string name;
	string description;
	string objectives; 
	string challenges; 
	string rewards;
	string zombies[MAX_ZOMBIES];
	Waves wave;
	Shovel shovel;

public:
	Levels(int num = 1) : plantFactory(), zombieFactory(), time(), num(num), name(), description(), objectives(), challenges(), rewards(), zombies(), wave(), shovel(),sunFactory() {}
	virtual ~Levels() {}
	PlantFactory& getPlantFactory() {
		return plantFactory;
	}
	ZombieFactory& getZombieFactory() {
		return zombieFactory;
	}
	SunFactory& getSunFactory() {
		return sunFactory;
	}
};

class BeginnersGarden : public Levels {
protected:
	BeginnersGarden() : Levels(1) {}
};


class Scoreboard {
protected:
	int score;
	string name;
public:
	Scoreboard(int score = 0, string name = "player 1") : score(score), name(name) {}
};

class Game {
protected:
	Scoreboard scoreboard;
	Levels levels;
	Grid grid;
	State* state;

public:
	Game() : scoreboard(), levels(), state(nullptr), grid() {} 
	void startGame() {
		//implement logic
	}
	Levels& getLevel() {
		return levels;
	}
	void setLevel(Levels& level) {
		levels = level;
	}
	void setScoreboard(Scoreboard& scoreboard) {
		this->scoreboard = scoreboard;
	}
	Scoreboard getScoreboard() {
		return scoreboard;
	}
	Grid& getGrid() {
		return grid;
	}
	
};


