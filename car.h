#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Car {
	protected:
		int damage;
		int x, y;
		bool exists;
		int speed;
		bool start;
		Texture carTexture;
		Sprite carSprite;
		Clock clock;

	
public:
	
	
	Car();
	void setstart(bool start) {
		this->start = start;
	}
	bool getstartt() {
		return start;
	}
	
	bool getexistscar() {
		return exists;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	void setx(int x) {
		this->x = x;
	}	
	void sety(int y) {
		this->y = y;
	}
	void setspeed(int speed) {
		this->speed = speed;
	}
	int getspeed() {
		return speed;
	}
	void setexistscar( bool exists) {
		this->exists = exists;
	}
	void movebasic()
	{
		if (exists) {
			if (start) {
				if (clock.getElapsedTime().asSeconds() > 0.0625)
				{
					x += speed;
					clock.restart();
				}
			}
		}

	}

};

class carfactory {
protected:
	Car car[5];
	Clock clock;
	sf::Texture carTexture[5];
	sf::Sprite carSprite[5];
public:
	carfactory();
	
	
	int getx(int i) {
		return car[i].getx();
	}
	int gety(int i) {
		return car[i].gety();
	}
	void setx(int i, int x) {
		car[i].setx(x);
	}
	void sety(int i, int y) {
		car[i].sety(y);
	}

	~carfactory()
	{
		
	}
	

	void setexists(int i,bool exists) {
		car[i].setexistscar(exists);
	}
	int  getexists(int i) {
		return car[i].getexistscar();
	}
	void drawCar(RenderWindow& window, int i);
	void movecar(int i);
	void setstart(int i , bool start) {
		 car[i].setstart(start);
	}
	bool getstart(int i) {
		return car[i].getstartt();
	}	
};
