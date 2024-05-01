#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Header.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;



//Drawing the background
void createBack() {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("Images/backwindow.jpg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

}

//Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;
	map_image.loadFromFile("Images/grid.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 160);

	window.draw(s_map);
}

void runSprite(Clock& clock, float animationSpeed, IntRect& textureRect, Sprite& textureSprite, int picLimit, float increment) {
	if (clock.getElapsedTime().asSeconds() > animationSpeed) {
		if (textureRect.left >= picLimit)
			textureRect.left = 0;
		else
			textureRect.left += increment;

		textureSprite.setTextureRect(textureRect);

		clock.restart();
	}
}


int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(800, 429), "Plants Vs Zombies");
	window.setMouseCursorVisible(false); // Hide cursor
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	sf::Texture cursorTexture;
	if (!cursorTexture.loadFromFile("Images/sword.png"))
		return 1; // Load your custom cursor image

	sf::Texture peaCursorTexture;
	if (!peaCursorTexture.loadFromFile("Images/peashootercursor.png"))
		return 1;
	sf::Texture sunflowerCursorTexture;
	if (!sunflowerCursorTexture.loadFromFile("Images/sunflowercursor.png"))
		return 1;
	sf::Texture snowPeaCursorTexture;
	if (!snowPeaCursorTexture.loadFromFile("Images/snowpeacursor.png"))
		return 1;
	sf::Texture repeaterCursorTexture;
	if (!repeaterCursorTexture.loadFromFile("Images/repeatercursor.png"))
		return 1;
	sf::Texture walnutCursorTexture;
	if (!walnutCursorTexture.loadFromFile("Images/walnutcursor.png"))
		return 1;
	sf::Texture cherryBombCursorTexture;
	if (!cherryBombCursorTexture.loadFromFile("Images/cherrybombcursor.png"))
		return 1;


	sf::Sprite cursor(cursorTexture);
	cursor.setScale(0.1f, 0.1f);

	Image map_image_back;
	//map_image_back.loadFromFile("C:/Users/PC/Desktop/OOP-Project/OOP-Project/Images/Game_field.png");//load the file for the map
	map_image_back.loadFromFile("Images/background2.png");//load the file for the map
	Texture map_back;
	map_back.loadFromImage(map_image_back);
	Sprite s_map_back;
	s_map_back.setTexture(map_back);
	s_map_back.setPosition(0, 0);

	Image map_image_shop;
	//map_image_shop.loadFromFile("C:/Users/PC/Desktop/OOP-Project/OOP-Project/Images/Game_field.png");//load the file for the map
	map_image_shop.loadFromFile("Images/shop.png");//load the file for the map
	Texture map_shop;
	map_shop.loadFromImage(map_image_shop);
	Sprite s_map_shop;
	s_map_shop.setTexture(map_shop);
	s_map_shop.setPosition(0, 0);

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	bool clicked = false;

	Clock timeMoney;

	Clock clock, clock1, clock2, clock3, clock4, clock5, clock6, clock7, clock8, clock9, clock10, clock11, clock12;
	float animationSpeed = 0.1;

	//-------------TEXTURES PLANTS N ZOMBEYES------------------

	sf::Texture peaShooterTexture;
	peaShooterTexture.loadFromFile("Images/Peashooter.png");
	sf::IntRect peaShooterRect(0, 0, 108, 130);
	sf::Sprite peaShooterSprite(peaShooterTexture, peaShooterRect);
	peaShooterSprite.setScale(0.5f, 0.5f);

	sf::Texture snowPeaShooterTexture;
	snowPeaShooterTexture.loadFromFile("Images/SnowPea.png");
	sf::IntRect snowPeaShooterRect(0, 0, 127, 131);
	sf::Sprite snowPeaShooterSprite(snowPeaShooterTexture, snowPeaShooterRect);
	snowPeaShooterSprite.setScale(0.5f, 0.5f);

	sf::Texture repeaterShooterTexture;
	repeaterShooterTexture.loadFromFile("Images/Repeater.png");
	sf::IntRect repeaterShooterRect(0, 0, 159, 157);
	sf::Sprite repeaterShooterSprite(repeaterShooterTexture, repeaterShooterRect);
	repeaterShooterSprite.setScale(0.5f, 0.5f);

	sf::Texture wallnutTexture;
	wallnutTexture.loadFromFile("Images/Walnut.png");
	sf::IntRect wallnutRect(0, 0, 108, 130);
	sf::Sprite wallnutSprite(wallnutTexture, wallnutRect);
	wallnutSprite.setScale(0.5f, 0.5f);

	sf::Texture cherryBombTexture;
	cherryBombTexture.loadFromFile("Images/CherryBomb.png");
	sf::IntRect cherryBombRect(0, 0, 331, 233);
	sf::Sprite cherryBombSprite(cherryBombTexture, cherryBombRect);
	cherryBombSprite.setScale(0.5f, 0.5f);

	sf::Texture sunflowerTexture;
	sunflowerTexture.loadFromFile("Images/Sunflower.png");
	sf::IntRect sunflowerRect(0, 0, 133, 150);
	sf::Sprite sunflowerSprite(sunflowerTexture, sunflowerRect);
	sunflowerSprite.setScale(0.5f, 0.5f);

	sf::Texture simpleZombieTexture;
	simpleZombieTexture.loadFromFile("Images/SimpleZombie.png");
	sf::IntRect simpleZombieRect(0, 0, 80, 100);
	sf::Sprite simpleZombieSprite(simpleZombieTexture, simpleZombieRect);
	//simpleZombieSprite.setScale(0.5f, 0.5f);

	sf::Texture dolphinZombieTexture;
	dolphinZombieTexture.loadFromFile("Images/DolphinZombie.png");
	sf::IntRect dolphinZombieRect(0, 0, 100, 110);
	sf::Sprite dolphinZombieSprite(dolphinZombieTexture, dolphinZombieRect);
	//dolphinZombieSprite.setScale(0.5f, 0.5f);

	sf::Texture dancingZombieTexture;
	dancingZombieTexture.loadFromFile("Images/DancingZombie.png");
	sf::IntRect dancingZombieRect(0, 0, 80, 130);
	sf::Sprite dancingZombieSprite(dancingZombieTexture, dancingZombieRect);
	dancingZombieSprite.setScale(0.9f, 0.9f);

	sf::Texture footballZombieTexture;
	footballZombieTexture.loadFromFile("Images/FootballZombie.png");
	sf::IntRect footballZombieRect(0, 118, 100, 100);
	sf::Sprite footballZombieSprite(footballZombieTexture, footballZombieRect);
	//footballZombieSprite.setScale(0.5f, 0.5f);

	sf::Texture flyingZombieTexture;
	flyingZombieTexture.loadFromFile("Images/flyingZombie edit.png");
	sf::IntRect flyingZombieRect(0, 0, 100, 135);
	sf::Sprite flyingZombieSprite(flyingZombieTexture, flyingZombieRect);
	flyingZombieSprite.setScale(0.75f, 0.75f);


	//-------------TEXTURE SEEDS------------------

	sf::Texture peaShooterSeedTexture;
	peaShooterSeedTexture.loadFromFile("Images/peashooter seed.png");
	sf::Sprite peaShooterSeedSprite(peaShooterSeedTexture);
	peaShooterSeedSprite.setScale(0.65f, 0.65f);
	peaShooterSeedSprite.setPosition(20, 13);

	sf::Texture sunflowerSeedTexture;
	sunflowerSeedTexture.loadFromFile("Images/sunflower seed.png");
	sf::Sprite sunflowerSeedSprite(sunflowerSeedTexture);
	sunflowerSeedSprite.setScale(0.65f, 0.65f);
	sunflowerSeedSprite.setPosition(90, 13);

	sf::Texture cherryBombSeedTexture;
	cherryBombSeedTexture.loadFromFile("Images/cherrybomb seed.png");
	sf::Sprite cherryBombSeedSprite(cherryBombSeedTexture);
	cherryBombSeedSprite.setScale(0.65f, 0.65f);
	cherryBombSeedSprite.setPosition(160, 13);

	sf::Texture walnutSeedTexture;
	walnutSeedTexture.loadFromFile("Images/walnut seed.png");
	sf::Sprite walnutSeedSprite(walnutSeedTexture);
	walnutSeedSprite.setScale(0.65f, 0.65f);
	walnutSeedSprite.setPosition(230, 13);

	sf::Texture snowPeaSeedTexture;
	snowPeaSeedTexture.loadFromFile("Images/snowpea seed.png");
	sf::Sprite snowPeaSeedSprite(snowPeaSeedTexture);
	snowPeaSeedSprite.setScale(0.65f, 0.65f);
	snowPeaSeedSprite.setPosition(300, 13);

	sf::Texture repeaterSeedTexture;
	repeaterSeedTexture.loadFromFile("Images/repeater seed.png");
	sf::Sprite repeaterSeedSprite(repeaterSeedTexture);
	repeaterSeedSprite.setScale(0.65f, 0.65f);
	repeaterSeedSprite.setPosition(370, 13);

	Game pvz;
	int selectedSeed = 0;

	while (window.isOpen())
	{

		/*runSprite(clock1, animationSpeed, peaShooterRect, peaShooterSprite, 756, 108);
		runSprite(clock2, animationSpeed, snowPeaShooterRect, snowPeaShooterSprite, 863, 127);
		runSprite(clock3, animationSpeed, repeaterShooterRect, repeaterShooterSprite, 597, 159);
		runSprite(clock4, animationSpeed, wallnutRect, wallnutSprite, 440, 111);
		runSprite(clock5, animationSpeed, cherryBombRect, cherryBombSprite, 3975, 331);
		runSprite(clock6, animationSpeed, simpleZombieRect, simpleZombieSprite, 560, 95);
		runSprite(clock7, animationSpeed, dolphinZombieRect, dolphinZombieSprite, 550, 103);
		runSprite(clock8, animationSpeed, dancingZombieRect, dancingZombieSprite, 240, 80);
		runSprite(clock9, animationSpeed, footballZombieRect, footballZombieSprite, 673, 97);
		runSprite(clock10, animationSpeed, flyingZombieRect, flyingZombieSprite, 900, 100);*/


		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();
		int sunNum = 0;

		//clock.restart();
		//time = time / 800;

		pvz.getLevel().getZombieFactory().createZombie("simpleZombie");

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			// Handle mouse button press
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					// Left mouse button is pressed
					// Add your logic here (e.g., shoot, select, etc.)

					cout << Mouse::getPosition(window).x << " , " << Mouse::getPosition(window).y << "  ";

					if (Mouse::getPosition(window).x >= 20 && Mouse::getPosition(window).x <= 90 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
						clicked = true;
						selectedSeed = 1;
						cursor.setTexture(peaCursorTexture);
					}
					else if (Mouse::getPosition(window).x >= 90 && Mouse::getPosition(window).x <= 160 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
						clicked = true;
						selectedSeed = 2;
						cursor.setTexture(sunflowerCursorTexture);
					}
					else if (Mouse::getPosition(window).x >= 160 && Mouse::getPosition(window).x <= 230 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
						clicked = true;
						selectedSeed = 3;
						cursor.setTexture(cherryBombCursorTexture);
					}
					else if (Mouse::getPosition(window).x >= 230 && Mouse::getPosition(window).x <= 300 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
						clicked = true;
						selectedSeed = 4;
						cursor.setTexture(walnutCursorTexture);
					}
					else if (Mouse::getPosition(window).x >= 300 && Mouse::getPosition(window).x <= 370 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
						clicked = true;
						selectedSeed = 5;
						cursor.setTexture(snowPeaCursorTexture);
					}
					else if (Mouse::getPosition(window).x >= 370 && Mouse::getPosition(window).x <= 440 && Mouse::getPosition(window).y >= 13 && Mouse::getPosition(window).y <= 79) {
						clicked = true;
						selectedSeed = 6;
						cursor.setTexture(repeaterCursorTexture);
					}

					if (Mouse::getPosition(window).x >= 180 && Mouse::getPosition(window).x <= 710 && Mouse::getPosition(window).y >= 60 && Mouse::getPosition(window).y <= 410) {
						int x = (Mouse::getPosition(window).x - 180) / 41;
						int y = (Mouse::getPosition(window).y - 60) / 53;
						cout << x << " , " << y << endl;
						if (FIELD_GAME_STATUS[x][y] == true && clicked) {
							FIELD_GAME_STATUS[x][y] = false;
							if (selectedSeed == 1)
								pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("peaShooter", Mouse::getPosition(window).x, Mouse::getPosition(window).y));
							else if (selectedSeed == 2)
								pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("sunflower", Mouse::getPosition(window).x, Mouse::getPosition(window).y));
							else if (selectedSeed == 3)
								pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("cherryBomb", Mouse::getPosition(window).x, Mouse::getPosition(window).y));
							else if (selectedSeed == 4)
								pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("walnut", Mouse::getPosition(window).x, Mouse::getPosition(window).y));
							else if (selectedSeed == 5)
								pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("snowPeaShooter", Mouse::getPosition(window).x, Mouse::getPosition(window).y));
							else if (selectedSeed == 6)
								pvz.getGrid().getTile(x, y).addPlant(pvz.getLevel().getPlantFactory().createPlant("repeaterShooter", Mouse::getPosition(window).x, Mouse::getPosition(window).y));
							cursor.setTexture(cursorTexture);
						}

					}
				}
			}
		}

		// Get mouse position
		Vector2i mousePosition = Mouse::getPosition(window);
		


		window.clear();
		window.draw(s_map_back);
		window.draw(s_map_shop);

		/*window.draw(cherryBombSprite);
		window.draw(peaShooterSprite);
		window.draw(repeaterShooterSprite);
		window.draw(wallnutSprite);
		window.draw(simpleZombieSprite);
		window.draw(dolphinZombieSprite);
		window.draw(dancingZombieSprite);
		window.draw(footballZombieSprite);
		window.draw(flyingZombieSprite);*/
		window.draw(peaShooterSeedSprite);
		window.draw(sunflowerSeedSprite);
		window.draw(snowPeaSeedSprite);
		window.draw(walnutSeedSprite);
		window.draw(repeaterSeedSprite);
		window.draw(cherryBombSeedSprite);

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				if (pvz.getGrid().getTile(i, j).getPlant() != nullptr) {
					pvz.getGrid().getTile(i, j).getPlant()->getSprite().setPosition(pvz.getGrid().getTile(i, j).getPlant()->getPosition().x, pvz.getGrid().getTile(i, j).getPlant()->getPosition().y);
					runSprite(pvz.getGrid().getTile(i, j).getPlant()->getClock(), animationSpeed, pvz.getGrid().getTile(i, j).getPlant()->getRect(), pvz.getGrid().getTile(i, j).getPlant()->getSprite(), pvz.getGrid().getTile(i, j).getPlant()->getlimitX(), pvz.getGrid().getTile(i, j).getPlant()->getIncrementX());
					window.draw(pvz.getGrid().getTile(i, j).getPlant()->getSprite());
				}
			}
		}

		
		window.draw(pvz.getLevel().getZombieFactory().getZombie(0)->getSprite());
		runSprite(clock6, animationSpeed, pvz.getLevel().getZombieFactory().getZombie(0)->getRect(), pvz.getLevel().getZombieFactory().getZombie(0)->getSprite(), 560, 95);
		pvz.getLevel().getZombieFactory().getZombie(0)->move();

		if (sunNum > 15) {
			sunNum = 0;
		}
		for (; sunNum < 15; sunNum++) {
			if (pvz.getLevel().getSunFactory().getSun(sunNum) != nullptr) {
				window.draw(pvz.getLevel().getSunFactory().getSun(sunNum)->getSprite());
				pvz.getLevel().getSunFactory().getSun(sunNum)->moveSun();
			}
			else {
				pvz.getLevel().getSunFactory().generateSun(sunNum);
			}
		}


		cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		window.draw(cursor);

		//window.setSize(sf::Vector2u(1170, 604.5));
		window.display();
	}
	return 0;
}
