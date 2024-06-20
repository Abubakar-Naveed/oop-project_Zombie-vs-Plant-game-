#pragma once
#ifndef MAINGAME_H_
#define MAINGAME_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Levels.h"


using namespace std;
using namespace sf;


class mainGame {
protected:
	levels* level[5];
	bool saveGame;
	int peashoooternum;
	int snowpeanum;
	int sunflowernum;
	int wallnutnum;
	int repeaternum;
	int cherrybombnum;
	bool cardplant;
	int levelnumber;
	MenuButton currency;
	string highestScore[3];
	int highScore[3];

public:
	mainGame();
	void readfromfile();
	bool savegame(bool save);
	void movegame(RenderWindow& window,Event event);
	void drawgrid(RenderWindow& window);
	void levelupdate(RenderWindow& window);
	void cardcheck(RenderWindow& window);
	void createplant(RenderWindow& window);
	void sunclick(RenderWindow& window);
	void savehighyScore();
	void readhighScore();
	bool getgameovermain();

};
#endif