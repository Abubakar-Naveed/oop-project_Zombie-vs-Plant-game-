#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
/// <summary>
/// int flea_x=(rand()%31) *32;
/*float flea[3] = {};
flea[x] = flea_x;
flea[y] = 0;
flea[exists] = false;
sf::Clock fleaClock;
sf::Texture fleaTexture;
sf::Sprite fleaSprite;
fleaTexture.loadFromFile("Textures/flea.png");
fleaSprite.setTexture(fleaTexture);
fleaSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
int checkflea = 0;
*/
/// </summary>

class Sun {
protected:
	
	int x;
	int y;
	bool exists;
	sf::Texture sunTexture;
	sf::Sprite sunSprite;
	sf::Clock sunclcock;
	bool check;
	int speed;
public:
	Sun();

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	int getx() { return x; }
	int gety() { return y; }
	void setexists(bool exists) { this->exists = exists; }
	bool getexists() { return exists; }
	void drawSun(sf::RenderWindow& window);
	void setposition(sf::Vector2f pos);
	void moveSun();
	bool isMousepressed(sf::RenderWindow& window);
	void moveSunForFlower();
	void setcheck(bool check) { this->check = check; }
	
};