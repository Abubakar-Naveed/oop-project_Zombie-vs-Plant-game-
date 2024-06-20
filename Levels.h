
#ifndef LEVELS_H_
#define LEVELS_H_
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Card.h" // Assuming Card.h is in the same directory
//#include "Plant.h"
#include "Sun.h"
#include"Car.h"
#include"PlantFactory.h"
//#include"zombie.h"
#include"button.h"
#include"../Project1/ZombieFacory.h"
using namespace sf;
using namespace std;

class levels {
public:
   
	
	MenuButton displaylives;
	int lives;
	bool gameover;
	int zomDiecheck;
	bool checklevels;
	bool zombiebool;
	int ZombieCount;
	int PlantCount;
	int score;
	/////plants
	int pesea = 0;
	Sun sun;
	/////////////////
	 carfactory *carr;
	//////////gridd///////
	bool boxcheck[5][9];
	Texture gridbuttonTexture[5][9];
	Sprite gridbuttonSprite[5][9];
	int x = 0, y = 0;
	bool check;
	
	///////////zombie
	normalZombie normalzombie;
	flyingZombie flyingzombie;

	zombie* zom[20];
	PlantFactory plantfactory;
	/////////////////////
	ZombieFactory zombiefactory;
	////////////////////

	///cards
	Card* card[9];
    int levelnum = 0;
    string name;
	sunbutton* sunn;
	RepeaterButton* repeaterbutton;
	SunflowerButton* sunflowerbutton;
	WallnutButton* wallnutbutton;
	PeashooterButton* peashooterbutton;
	CherryBombButton* cherrybombbutton;
	SnowPeaButton* snowpeabutton;
	exitCard* exitcard;

	//ChomperButton* chomperbutton;
    

public:
	void setx(int x);
	void sety(int y);
	int getx() { return x; }
	int gety() { return y; }
	bool isboxcheck();
	void setposition(Vector2f pos);
	void drawGrid(RenderWindow& window);
	Card* getCard(int i) { return card[i]; }
	levels();
    void drawLevel(RenderWindow& window,int levelnum,Event e) ;
    virtual ~levels(); // Virtual destructor
	bool isMouseOver(RenderWindow& window);
	int getpesea() { return pesea; }
	void setpesea(int pesea) { this->pesea = pesea; }
	void drawSunandMove(RenderWindow& window);
	void setcardbutton(bool hello,int index);
	bool getcardbutton(int index);
	bool checklevel();
	void setzombiecount(int count);
	void setplantcount(int count);
	int getzombiecount()
	{
		return ZombieCount;

	}
	int getplantcount()
	{
		return PlantCount;

	}

	int getlives();
	void setlives(int lives);
	bool getgameover();
	int getscore() { return score; }
	void setwallnummove(int i, bool move) { plantfactory.wallnut[i].setMove(move); }
//	void setlives(int lives ) { this->lives= lives; }

};


class level1 : public levels {
protected:
	int levelnum = 1;
public:
   // RepeaterButton* peashooterbutton;
	level1();
	
	~level1();

	
};


#endif // !LEVELS_H_


class level2 : public levels {
protected:
public:

	level2();
	//level2(int levelnum);
	~level2() {}
	


};
class level3 : public levels {
public:
	level3();
	
	~level3(){}
};
class level4 : public levels {
public:
	level4();
	
	~level4(){}
};
class level5 : public levels {
public:
	level5();
	
	~level5(){}

};
