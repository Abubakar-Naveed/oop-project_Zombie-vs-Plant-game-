#include<iostream>
#include <SFML/Graphics.hpp>
#include"../Project1/Car.h"
using namespace std;
using namespace sf;
Car::Car() {
	damage = 0;
	x = 0; y = 0;
	exists = true;
	speed = 15;
	start = false;

}
carfactory::carfactory() {
	for (int i = 0; i < 5; i++) {
	
		carTexture[i].loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\Car.png");
		carSprite[i].setTexture(carTexture[i]);
		carSprite[i].setScale(0.7f, 0.7f);
		
		car[i].setstart(false);
		
		car[i].setx(124);
		car[i].sety(96 + i * 112);
	
	}
}
void carfactory::drawCar(RenderWindow& window, int i) {
	
		if (car[i].getexistscar()) {
			carSprite[i].setPosition(car[i].getx(), car[i].gety());
			window.draw(carSprite[i]);
		}
	
}


void carfactory::movecar(int i)
{
	car[i].movebasic();
}	