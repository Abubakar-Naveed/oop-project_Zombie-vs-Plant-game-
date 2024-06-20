#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "Button.h"

class mainmenu {
protected:
	MenuButton menubutton[5];
	Image image;
	Texture menuTexture;
	Sprite menuSprite;
public:
	mainmenu();
	void loadmenu(RenderWindow& window);
	void drawmenu(RenderWindow& window);
	
	int checkclick(RenderWindow& window);

};

class instructions  {
protected:
	MenuButton instructionbutton;
	Image image;
	Texture instructionTexture;
	Sprite instructionSprite;
public:
	instructions();
	void loadinstructions(RenderWindow& window);
	void drawinstructions(RenderWindow& window);
	int checkclick(RenderWindow& window);


};

class highestscore {
protected:
	MenuButton scorebutton;
	Image image;
	Texture scoreTexture;
	Sprite scoreSprite;
public:
	highestscore();
	void loadscore(RenderWindow& window);
	void drawscore(RenderWindow& window);
	int checkclick(RenderWindow& window);
};



class Entername {
protected:
	MenuButton getnamebutton;
	MenuButton playbutton;

	Image image;
	Texture nameTexture;
	Sprite nameSprite;
public:
	Entername();
	void loadname(RenderWindow& window);
	void drawname(RenderWindow& window);
	int checkclick(RenderWindow& window);
	void setname(RenderWindow& window,string text);

};



class pausegame {
protected:
	MenuButton pausebutton;
	Image image;
	Texture pauseTexture;
	Sprite pauseSprite;
public:
	pausegame();
	void loadpause(RenderWindow& window);
	void drawpause(RenderWindow& window);
	int checkclick(RenderWindow& window);


};


class resume {

protected:
	MenuButton resumebutton[2];
	Image image;
	Texture resumeTexture;
	Sprite resumeSprite;

public:
	resume();
	void loadresume(RenderWindow& window);
	void drawresume(RenderWindow& window);
	int checkclick(RenderWindow& window);
};


