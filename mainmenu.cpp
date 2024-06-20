#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "mainmenu.h"

mainmenu::mainmenu()
{
	
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\title.png");
	menuTexture.loadFromImage(image);
	menuSprite.setTexture(menuTexture);
	menuSprite.setPosition(0, 0);
	menuSprite.setScale(0.62f, 0.65f);
	
}


	//menubutton[5];


int mainmenu::checkclick(RenderWindow& window)
{
	bool status = false;
	for (int i = 0; i < 5; i++)
	{

		if ( menubutton[i].MouseInArea(window))
		{
			cout << "i  is " << i << "\n";
			return i;
			
		}

	}

	return -1;
	//menubutton[4];
}
void mainmenu::loadmenu(RenderWindow& window)
{
	
	menubutton[0].setMenuButton(window, "New Game",240 , 490, 20);
	menubutton[1].setMenuButton(window, "Old Game", 390, 490, 20);
	menubutton[2].setMenuButton(window, "Instructions", 540, 490, 20);
	menubutton[3].setMenuButton(window, "Exit", 680, 490, 20);
	menubutton[4].setMenuButton(window, "Highest Score", 810, 490, 20);

}

void mainmenu::drawmenu(RenderWindow& window)
{
	window.draw(menuSprite);
	
	for (int i = 0; i < 5; i++)
	{
		menubutton[i].Draw_button(window);
	}
	
	

}

/////////////////instruction////////////////////////

instructions::instructions()
{
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Instructions.jpg");
	instructionTexture.loadFromImage(image);
	instructionSprite.setTexture(instructionTexture);
	instructionSprite.setPosition(0, 0);
	instructionSprite.setScale(0.58f, 0.6f);
}

int instructions::checkclick(RenderWindow& window)
{
	bool status = false;
	

	if (instructionbutton.MouseInArea(window))
	{
		cout << "i am in instruction checkclick\n";
		return -1;
	}
	return 2;
	//menubutton[4];
}

void instructions::loadinstructions(RenderWindow& window)
{
	instructionbutton.setMenuButton(window, "Back", 1000, 600, 20);
}

void instructions::drawinstructions(RenderWindow& window)
{
	window.draw(instructionSprite);
	instructionbutton.Draw_button(window);
}

/////////////////highestscore////////////////////////

highestscore::highestscore()
{
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Leaderboard.jpg");
	scoreTexture.loadFromImage(image);
	scoreSprite.setTexture(scoreTexture);
	scoreSprite.setPosition(0, 0);
	scoreSprite.setScale(1.7f, 1.7f);
}

int highestscore::checkclick(RenderWindow& window)
{
	bool status = false;

	if (scorebutton.MouseInArea(window))
	{
		cout << "i am in highestscore checkclick\n";
		return -1;
	}
	return 4;
}

void highestscore::loadscore(RenderWindow& window)
{
	scorebutton.setMenuButton(window, "Back", 1000, 600, 20);
}

void highestscore::drawscore(RenderWindow& window)
{
	window.draw(scoreSprite);
	scorebutton.Draw_button(window);
}

/////////////////Entername////////////////////////

Entername::Entername()
{
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\name screen.jpg");
	nameTexture.loadFromImage(image);
	nameSprite.setTexture(nameTexture);
	nameSprite.setPosition(0, 0);
	nameSprite.setScale(1.7f, 1.7f);
}

int Entername::checkclick(RenderWindow& window)
{
	bool status = false;

	if (getnamebutton.MouseInArea(window))
	{
		return -2;
	}
	if (playbutton.MouseInArea(window))
	{
		return -1;
	}

}

void Entername::loadname(RenderWindow& window)
{
	getnamebutton.setMenuButton(window, "", 400, 500, 20);
	playbutton.setMenuButton(window, "Play", 400, 500, 20);
}

void Entername::drawname(RenderWindow& window)
{
	window.draw(nameSprite);
	getnamebutton.Draw_button(window);
	playbutton.Draw_button(window);
}

void Entername::setname(RenderWindow& window ,string text )
{
	getnamebutton.setMenuButton(window, text, 500, 300, 20);
}


//////////////pause/////////////////////////

pausegame::pausegame()
{
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\title.png");
	pauseTexture.loadFromImage(image);
	pauseSprite.setTexture(pauseTexture);
	pauseSprite.setPosition(0, 0);
	pauseSprite.setScale(1.7f, 1.7f);
}


void pausegame::loadpause(RenderWindow& window)
{
	pausebutton.setMenuButton(window, "Pause", 400, 500, 20);
}

void pausegame::drawpause(RenderWindow& window)
{
	window.draw(pauseSprite);
	pausebutton.Draw_button(window);
}

int pausegame::checkclick(RenderWindow& window)
{
	bool status = false;

	if (pausebutton.MouseInArea(window))
	{
		return -1;
	}
	return 0;
}


/////////////
resume::resume()
{
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\optionscreen.jpg");
	resumeTexture.loadFromImage(image);
	resumeSprite.setTexture(resumeTexture);
	resumeSprite.setPosition(0, 0);
	resumeSprite.setScale(1.06f, 1.06f);
}

void resume::loadresume(RenderWindow& window)
{
	resumebutton[0].setMenuButton(window, "Resume", 450, 300, 20);
	resumebutton[1].setMenuButton(window, "Exit", 450, 400, 20);
}

void resume::drawresume(RenderWindow& window)
{
	window.draw(resumeSprite);
	for (int i = 0; i < 2; i++)
	{
		resumebutton[i].Draw_button(window);
	}
}

int resume::checkclick(RenderWindow& window)
{
	bool status = false;

	for (int i = 0; i < 2; i++)
	{

		if (resumebutton[i].MouseInArea(window))
		{
			cout << "i  is " << i << "\n";
			return i;

		}

	}

	return 5;
	//menubutton[4];
}