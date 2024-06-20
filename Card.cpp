//#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include"../Project1/Card.h"
using namespace sf;
using namespace std;

///////////////exist card/////////////
void exitCard::setclickButton(bool click) {
	// Implementation of setclickButton for Card

	buttonClick = click;
}
bool exitCard::clickButton() {
	// Implementation of clickButton for Card

	return buttonClick;
}
void exitCard::drawButton(RenderWindow& window) {
	// Drawing the exit button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\repeatercard.png");

	// Create texture and sprite
	Texture buttonTexture;
	buttonTexture.loadFromImage(buttonImage);
	Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// Set position of the button sprite
	buttonSprite.setPosition(1008, 0);

	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}
void exitCard::setposition(Vector2f pos)
{
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;

}

bool exitCard::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		cout << "Pause button is pressed\n";
		return true;
	}
	cout << "Pause button is false\n";
	return false;
}

string exitCard::getButtonName() {
	// Implementation of getButtonName for Card

	return buttonName;
}

//////////////////////////////////


void RepeaterButton::setclickButton(bool click) {
	// Implementation of setclickButton for RepeaterButton

	buttonClick = click;
}

bool RepeaterButton::clickButton() {
    // Implementation of clickButton for RepeaterButton

    return buttonClick;
}

void RepeaterButton::drawButton(RenderWindow& window) {
    // Drawing the repeater button

    // Load button image
   
	Image buttonImage;
    buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\repeatercard.png");

    // Create texture and sprite
   
	buttonTexture.loadFromImage(buttonImage);
    
    buttonSprite.setTexture(buttonTexture);

    // Set position of the button sprite
    buttonSprite.setPosition(560,0);

    // Draw the button sprite onto the window
    window.draw(buttonSprite);
}
void RepeaterButton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = (pos.x + buttonSprite.getLocalBounds().width/2);
	float y = (pos.y + buttonSprite.getLocalBounds().height / 2);

	
	cout << "x=" << x << "y=" << y << endl;


}
bool RepeaterButton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		return true;
	}
	return false;

}


string RepeaterButton::getButtonName() {
    return buttonName;
    // Implementation of getButtonName for RepeaterButton
}


/////////////define all function of remaing classes/////////////////
/////SunflowerButton///////////

/////////WallnutButton///////////

void WallnutButton::setclickButton(bool click) {
	// Implementation of setclickButton for WallnutButton

	buttonClick = click;
}
string WallnutButton::getButtonName() {
	// Implementation of getButtonName for WallnutButton

	return buttonName;
}
bool WallnutButton::clickButton() {
	// Implementation of clickButton for WallnutButton

	return buttonClick;
}
void WallnutButton::drawButton(RenderWindow& window) {
	// Drawing the Wallnut button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\img3.png");

	// Create texture and sprite
	//Texture buttonTexture;
	buttonTexture.loadFromImage(buttonImage);
	//Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// Set position of the button sprite
	buttonSprite.setPosition(336, 0);
	buttonSprite.setColor(sf::Color(255, 255, 255, 255 * 1)); // Reduces Opacity to 25%


	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}

bool WallnutButton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		return true;
	}
	return false;
}

void WallnutButton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;
}

////////PeashooterButton///////////
void  PeashooterButton::setclickButton(bool click) {
	// Implementation of setclickButton for PeashooterButton
	cout << "setclickButton" << endl;
	cout << "click=" << click << endl;
	buttonClick = click;
}
string PeashooterButton::getButtonName() {
	// Implementation of getButtonName for PeashooterButton
	return buttonName;
}
bool PeashooterButton::clickButton() {
	// Implementation of clickButton for PeashooterButton
	return buttonClick;
}

void PeashooterButton::drawButton(RenderWindow& window) {
	// Drawing the Peashooter button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\img1.png");

	// Create texture and sprite
	//Texture buttonTexture;
	buttonTexture.loadFromImage(buttonImage);
	//Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// Set position of the button sprite
	buttonSprite.setPosition(112, 0);
	buttonSprite.setColor(sf::Color(255, 255, 255, 255 * 1)); // Reduces Opacity to 25%


	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}
void PeashooterButton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;
}
bool PeashooterButton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		return true;
	}
	return false;
}


////////CherryBombButton///////////
void CherryBombButton::setclickButton(bool click) {
	// Implementation of setclickButton for CherryBombButton

	buttonClick = click;
}
string CherryBombButton::getButtonName() {
	// Implementation of getButtonName for CherryBombButton
	return buttonName;
}
bool CherryBombButton::clickButton() {
	// Implementation of clickButton for CherryBombButton
	return buttonClick;
}
void CherryBombButton::drawButton(RenderWindow& window) {
	// Drawing the CherryBomb button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\cherrycard.png");

	// Create texture and sprite
	//Texture buttonTexture;
	buttonTexture.loadFromImage(buttonImage);
	//Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	// Set position of the button sprite
	buttonSprite.setPosition(448, 0);
	buttonSprite.setColor(sf::Color(255, 255, 255, 255 * 1)); // Reduces Opacity to 25%

	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}
void CherryBombButton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;
}
bool CherryBombButton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		return true;
	}
	cout << "Mouse position x=" << mousePos.x << "y=" << mousePos.y << endl;
	cout << "pos x=" << pos.x << "pos y=" << pos.y << endl;
	return false;
}



////////SnowPeaButton///////////
void SnowPeaButton::setclickButton(bool click) {
	// Implementation of setclickButton for SnowPeaButton

	buttonClick = click;
}
string SnowPeaButton::getButtonName() {
	// Implementation of getButtonName for SnowPeaButton

	return buttonName;
}
bool SnowPeaButton::clickButton() {
	// Implementation of clickButton for SnowPeaButton

	return buttonClick;
}
void SnowPeaButton::drawButton(RenderWindow& window) {
	// Drawing the SnowPea button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\snowcard.png");

	// Create texture and sprite
	//Texture buttonTexture;
	buttonTexture.loadFromImage(buttonImage);
	//Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// Set position of the button sprite
	buttonSprite.setPosition(224, 0);
	buttonSprite.setColor(sf::Color(255, 255, 255, 255 * 1)); // Reduces Opacity to 25%


	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}
void SnowPeaButton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;
}
bool SnowPeaButton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		return true;
	}
	return false;
}


////////sunbutton///////////
string sunbutton::getButtonName() {
	// Implementation of getButtonName for sunbutton

	return buttonName;
}
bool sunbutton::clickButton() {
	// Implementation of clickButton for sunbutton

	return true;
}
void sunbutton::drawButton(RenderWindow& window) {
	// Drawing the sunbutton button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\img1.png");

	// Create texture and sprite
	Texture buttonTexture;
	buttonTexture.loadFromImage(buttonImage);
	Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// Set position of the button sprite
	buttonSprite.setPosition(672, 0);

	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}
void sunbutton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;
}
bool sunbutton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		return true;
	}
	return false;
}
void sunbutton::setclickButton(bool click) {
	// Implementation of setclickButton for sunbutton

	buttonClick = click;
}

////////sunflowerbutton///////////


string SunflowerButton::getButtonName() {
	// Implementation of getButtonName for SunflowerButton

	return buttonName;
}
void SunflowerButton::setposition(Vector2f pos) {
	buttonSprite.setPosition(pos);
	float x = buttonSprite.getPosition().x;
	float y = buttonSprite.getPosition().y;
	cout << "x=" << x << "y=" << y << endl;
}
void SunflowerButton::drawButton(RenderWindow& window) {
	// Drawing the Sunflower button

	// Load button image
	Image buttonImage;
	buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\sunlowerbuttonnew.jpg");
	//buttonImage.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\img2.png");

	// Create texture and sprite
	
	buttonTexture.loadFromImage(buttonImage);
	buttonSprite.setTexture(buttonTexture);

	// Set position of the button sprite
	buttonSprite.setPosition(0, 0);
	buttonSprite.setScale(0.4f, 0.4f);
	// Draw the button sprite onto the window
	window.draw(buttonSprite);
}
bool SunflowerButton::clickButton() {
	// Implementation of clickButton for SunflowerButton

	return buttonClick;
}
void SunflowerButton::setclickButton(bool click) {
	// Implementation of setclickButton for SunflowerButton

	buttonClick = click;
}
bool SunflowerButton::isMousepressed(RenderWindow& window) {
	Vector2i mousePos = Mouse::getPosition(window);
	Vector2f pos = buttonSprite.getPosition();
	FloatRect bounds = buttonSprite.getLocalBounds(); // Get the local bounds of the sprite
	if (mousePos.x > pos.x && mousePos.x < pos.x + bounds.width &&
		mousePos.y > pos.y && mousePos.y < pos.y + bounds.height) {
		cout << "I am sunflower\n";
		return true;
	}
	return false;
}




