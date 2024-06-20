#include"sun.h"
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
Sun::Sun() {
	exists = false;
	check = false;
	x = (rand()%20)*32 + 224;
	y = 0;
	sunTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\sun.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setPosition(0, 0);
	sunSprite.setScale(0.5f, 0.4f);
}
void Sun::drawSun(RenderWindow& window) {
	
		sunSprite.setPosition(x, y);
		window.draw(sunSprite);
	
}
void Sun::setposition(Vector2f pos) {
	sunSprite.setPosition(pos);

}
void Sun::moveSun() {
	

		if (sunclcock.getElapsedTime().asSeconds() > 0.0625)
		{
			y += 3;
			sunclcock.restart();
		}
		if (y > 700)
		{
			y = -400;
			x = (rand() % 15) * 32   + 224;

		}
	
}
void Sun::moveSunForFlower() {
	if (check == false)
	{
		if (sunclcock.getElapsedTime().asSeconds() > 5)
		{
			y += 48;
			sunclcock.restart();
			check = true;
		}
	 
	}
}
bool Sun::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f translatedPos = window.mapPixelToCoords(mousePos);
	if (sunSprite.getGlobalBounds().contains(translatedPos)) 
	{
		return true;
	}
	return false;
}
