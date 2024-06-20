
#ifndef PLANT_H_
#define PLANT_H_

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"bullet.h"
#include"sun.h"

// Assuming Card.h is in the same directory
using namespace sf;
using namespace std;

class plant {
protected:
	bool bulltmove;
	sf::Texture plantTexture;
	sf::Sprite plantSprite;
	Clock clock;
	Image image;
	int price;
	int health;
	int damage;
	bool isAlive;
	bool isAttacking;
	bool zombieInRange;
	int x, y;
	int doDamage;
	//int zombieX, zombieY;
	bool bulletcheck;
public:
	plant();
	///make paramaterized constructor for seeting all the values
	void setvalues(int price, int health, int damage, bool isAlive, bool isAttacking, bool zombieInRange,int x,int y);

	plant(int price, int health, int damage);
	int getPrice();
	int getHealth();
	int getDamage();
	bool getIsAlive();
	bool getIsAttacking();
	bool getZombieInRange();
	//void setposition(Vector2f pos);
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	int getx() { return x; }
	int gety() { return y; }
	void sethealth(int health);
	void setdamage(int damage);
	void setIsAlive(bool isAlive);
	void setisAttacking(bool isAttacking);
	void setzombieInRange(bool zombieInRange);
	void setprice(int price);
	void drawPlant(RenderWindow& window, int x, int y);
	void setbulletcheck(bool bulletcheck) { this->bulletcheck = bulletcheck; }
	bool getbulletcheck() { return bulletcheck; }
	int  getDoDamage() { return doDamage; }
	//level->peashooter[i].setposition(Vector2f(level->getx(), level->gety()));
	
	void setposition(Vector2f pos) {
		x = pos.x;
		y = pos.y;
	}
};
class Peashooter : public plant , public bullet{
protected:
	PeaBullet bullet;

	
public:
	PeaBullet getBullet() { 
	//	cout << "Bullet is  : " << bullet.getcheck() << "\n";
		return bullet; }
	Peashooter();
	FloatRect getGlobalBoundsforBullet() const;
	void setAttack();	
	void attack(RenderWindow& window);
	
	int  getbulletx() {
		return  bullet.getx(); 
	}
	int  getbullety() { return bullet.gety(); }
	void bulletSetExists(bool exists) {
		bullet.bulletsetexists(exists);
	}
	bool getpeabullect() {
		return bullet.bulletgetexists();
	}
	int  peahshootergetbulletx() {
		return bullet.getx();
	}
	int  peashootergetbullety() { return bullet.gety(); }

};
class Sunflower : public plant , public Sun{
protected:
	bool check;
public:
	Sunflower();
	//void drawSunForFlower(sf::RenderWindow& window);
	void moveSunForFlower(RenderWindow& window);
	void setSunflower(bool check) { this->check = check; }
	bool getSunflower() { return check; }

};

class Wallnut : public plant {
protected:
	bool move;

public:
	Wallnut();
	void moveWallnut(bool move) {
		if (clock.getElapsedTime().asSeconds() > 0.03125)
		{
			if (move == true && isAttacking==false)
			{
				x += 4;
				clock.restart();
			}
		}

	}
	void setMove(bool move) { this->move = move; }
	bool getMove() { return move; }

};

class CherryBomb : public plant {
protected:
	bool attackRange;
	bool attack;
public:
	CherryBomb();
	void setAttack(bool hello);
	void setattackrange();

};
class SnowPea : public plant {
protected:
	SnowBullet bullet;
public:
	SnowPea();
	FloatRect getGlobalBoundsforBullet() const;
	SnowBullet getBullet() { return bullet; }
	void setAttack();
	void attack(RenderWindow& window);

	int  getbulletx() {
		return  bullet.getx();
	}
	int  getbullety() { return bullet.gety(); }
	void bulletSetExists(bool exists) {
		bullet.bulletsetexists(exists);
	}

};
class Repeater : public plant {
protected:
	RepeaterBullet bullet[2];
	bool bulletcheckrepeater[2];
public:
	Repeater();
	void setAttack();
	void attack(RenderWindow& window);
	void bulletSetExists(bool exists,int i) {
		if(i==0)
		{ 
			bullet[0].bulletsetexists(exists);
		}
		else if (i == 1)
		{
			bullet[1].bulletsetexists(exists);
		}
		
	}
	RepeaterBullet getBullet(int i) { return bullet[i]; }
	void setbulletcheckrepeater(bool bulletcheckrepeater, int i) {
		if (i == 0)
		{
			this->bulletcheckrepeater[0] = bulletcheckrepeater;
		}
		else if (i == 1)
		{
			this->bulletcheckrepeater[1] = bulletcheckrepeater;
		}
	}
	bool getbulletcheckrepeater(int i) {
		if (i == 0)
		{
			return bulletcheckrepeater[0];
		}
		else if (i == 1)
		{
			return bulletcheckrepeater[1];
		}
	}	

};
#endif // !PLANT_H_
