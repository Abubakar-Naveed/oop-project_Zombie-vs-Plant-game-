#include<iostream>
#include<SFML/Graphics.hpp>
#include"Zombie.h"
using namespace std;
using namespace sf;
zombie::zombie() {
	
	for (int i = 0; i < 60; i++)
	{
		movement[i] = false;
	}
	speed = 0;
	health = 0;
	x = 0;
	y = 0;
	isAlive = true;
	isAttacking = false;
	plantInRange = false;
	stop = false;
}
void zombie::setvalues(int health, int x, int y, bool isAlive) {
	this->health = health;
	this->x = x;
	this->y = y;
	this->isAlive = isAlive;

}
int zombie::getHealth() {
	return health;
}
void zombie::drawZombie(RenderWindow& window) {
	if (isAlive)
	{
		zombieSprite.setPosition(x, y);
		window.draw(zombieSprite);
	//	cout << "zombie is done\n";

	}
}
void zombie::setstop(bool stopp) {
	stop = stopp;
}
void zombie :: setstoptrue()
{
	if (clock.getElapsedTime().asSeconds() > 2)
	{
		stop = false;
		clock.restart();
	}
}

void zombie::moveZombie(int num) {
	if (clock.getElapsedTime().asSeconds() > 0.03125)
	{
		if (stop == false)
		{

			if (num <= 30)
			{
				x -= (2 + speed);
				clock.restart();
			}
			if (num >= 30 && num <= 40)
			{
				if ((movement[num] == false) && (32 * 10) <= x && (32 * 20) >= x)
				{
					y += 4;
				}
				x -= (4 + speed);
				clock.restart();

				if (y >= 592)
				{
					movement[num] = true;
				}
				if (y <= 96)
				{
					movement[num] = false;
				}
				if (movement[num] == true && x >= 32 * 10)
				{
					y -= 4;
				}

			}
		}
	}
}
void zombie::setposition(Vector2f pos) {
	zombieSprite.setPosition(pos);
}	
bool zombie::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f translatedPos = window.mapPixelToCoords(mousePos);
	if (zombieSprite.getGlobalBounds().contains(translatedPos))
	{
		return true;
	}
	return false;
}
void zombie::setzombiexy(int x, int y) {
	this->x = x;
	this->y = y;
}

//////////////////////simple zombie
normalZombie::normalZombie() {
	health = 100;
	
	isAlive = true;
	isAttacking = false;
	plantInRange = false;
	zombieTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\pngwing.com (1).png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(0.08f, 0.07f);
}
//////////////////////fyling zombie
flyingZombie::flyingZombie() {
	health = 100;
	speed = 0;
	isAlive = true;
	isAttacking = false;
	plantInRange = false;
	zombieTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\clipart2658868.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(0.13f, 0.13f);
}
//////////////////////football zombie///////////////////
footballZombie::footballZombie() {
	health = 100;
	speed = 1;
	isAlive = true;
	isAttacking = false;
	plantInRange = false;
	zombieTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Football_zombie (1).png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(0.13f, 0.13f);
}

//////////////////////////
dancingZombie::dancingZombie() {
	health = 100;
	speed = 0;
	isAlive = true;
	isAttacking = false;
	plantInRange = false;
	zombieTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\dancerZombie (1).png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(0.09f, 0.09f);
}

//////////////////////////
DolphinRiderZombie::DolphinRiderZombie() {
	health = 100;
	speed = 2;
	isAlive = true;
	isAttacking = false;
	plantInRange = false;
	zombieTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\DolphinZombie.png");
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(0.4f, 0.4f);
}