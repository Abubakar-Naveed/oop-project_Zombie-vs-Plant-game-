#include"bullet.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include"bullet.h"
using namespace std;
using namespace sf;
void bullet::bulletsetexists(bool exists) {
	

	this->exists = exists;
}

bullet::bullet() {
	
	x = 0;
	y = 0;
	damage = 0;
	exists = false;
	speed = 6;
	check = false;


}
bullet::bullet(int damage) {
	this->damage = damage;
	exists = false;
	
}
void bullet::setdamage(int damage) {
	this->damage = damage;
}
int bullet::getdamage() {
	return damage;
}
void bullet::drawBullet(RenderWindow& window) {
	if (exists) {
		bulletSprite.setPosition(x, y);
		window.draw(bulletSprite);
		
	}
}
void bullet::setposition(Vector2f pos) {
	bulletSprite.setPosition(pos);

}
void bullet::moveBullet() {
	//
	if ((clock.getElapsedTime().asSeconds()>0.0625))
	{
		if (exists)
		{
			x = x + speed;
			clock.restart();
			//cout << "heloooooooooooooooooooooooooooooooooooooooooooo  " <<x<< endl;
		}//cout << "bullet moved  " << y << endl;
	}				
}
bool bullet::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f translatedPos = window.mapPixelToCoords(mousePos);
	if (bulletSprite.getGlobalBounds().contains(translatedPos))
	{
		return true;
	}
	return false;
}

/////////
PeaBullet::PeaBullet() {
	damage = 0;
	exists = false;
	speed = 12;
	bulletTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\peabullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(0.7f, 0.7f);
}

/////////////
SnowBullet::SnowBullet() {
	damage = 0;
	exists = false;
	speed = 12;
	bulletTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\snowbullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(0.7f, 0.7f);
}

////////
RepeaterBullet::RepeaterBullet() {
	damage = 0;
	exists = false;
	speed = 16;
	bulletTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\peabullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(0.7f, 0.7f);
}