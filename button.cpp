#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "Button.h"

#include<SFML/Graphics.hpp>

//#include "../OOP_Pro/Game.cpp"
//using namespace std;



MenuButton::MenuButton()
{
	
	text.setString("  ");
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(10);
	button_sprite.setPosition(50, 50);
	image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\menubutton.png");
	button_texture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\menubutton.png");
	button_sprite.setTexture(button_texture);
	//button_sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	font.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Project1\\arial.ttf");


}

void MenuButton::setMenuButton(sf::RenderWindow& window, string textt, int X_position, int Y_position, int text_size)
{


	this->text.setString(textt);
	button_sprite.setPosition(50, 50);
	button_sprite.setPosition(X_position, Y_position);
	button_texture.loadFromImage(image);

	button_sprite.setTexture(button_texture);
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(text_size);
	float textX = X_position + (button_sprite.getLocalBounds().width - this->text.getLocalBounds().width) / 2;
	float textY = Y_position + (button_sprite.getLocalBounds().height - this->text.getLocalBounds().height) / 2 - this->text.getLocalBounds().top;
	this->text.setPosition(textX, textY);

}

int MenuButton::getX_position() const {
	return X_position;
}

int MenuButton::getY_position() const {
	return Y_position;
}

// Setters
void MenuButton::setX_position(int x) {
	X_position = x;
}

void MenuButton::setY_position(int y) {
	Y_position = y;
}

bool MenuButton::MouseInArea(sf::RenderWindow& window)
{
	float posX = sf::Mouse::getPosition(window).x;
	float posY = sf::Mouse::getPosition(window).y;
	//cout << "X	"<<posX << "	Y	"<<posY<<endl;
	cout << "hello\n";
	float buttonX = button_sprite.getPosition().x;
	float buttonY = button_sprite.getPosition().y;
	//cout << "X	" << buttonX << "	Y	" << buttonY << endl<<endl;
	float buttonLimitX = button_sprite.getPosition().x + button_sprite.getLocalBounds().width;
	float buttonLimitY = button_sprite.getPosition().y + button_sprite.getLocalBounds().height;
	//cout << "X	" << buttonLimitX << "	Y	" << buttonLimitY << endl;
	if (posX < buttonLimitX && posX>buttonX && posY < buttonLimitY && posY > buttonY)
	{
		//cout << "ON BUTTON\n";
		cout << "i am returning true\n";
		return true;
	}
	cout << "i am returning false\n";
	return false;
}

void MenuButton::Draw_button(sf::RenderWindow& window)
{
	window.draw(button_sprite);
	window.draw(this->text);
}

void MenuButton::Highlight()
{
	//button_sprite.setScale(1.2f, 1.2f);
	button_sprite.setColor(sf::Color(200, 200, 200));
}

void MenuButton::Original()
{
	//button_sprite.setScale(1.2f, 1.2f);
	button_sprite.setColor(sf::Color::White);
	//button_texture.loadFromFile("E:\\Uni Content\\Semester_02\\OOP\\OOP_Pro\\Images\\button.jpg");
}


/////////////////////////////////////////
//class namebutton

