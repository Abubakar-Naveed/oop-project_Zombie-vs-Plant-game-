#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Card {
protected:
    bool buttonClick;
    int suns=0;
    string buttonName;
	Texture buttonTexture;
	Sprite buttonSprite;

public:

    
	virtual bool clickButton() = 0; // Pure virtual function
	virtual void setclickButton(bool click) = 0;
	virtual void drawButton(RenderWindow& window) = 0; // Pure virtual function
    virtual string  getButtonName() = 0; // Pure virtual function
	virtual void setposition(Vector2f pos) = 0 ;
	virtual bool isMousepressed(RenderWindow& window) = 0;

};

class RepeaterButton : public Card {
public:
   
	void setclickButton(bool click) override;
	bool clickButton() override;
    void drawButton(RenderWindow& window)  override;
    string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;
};

class PeashooterButton : public Card {
public:
	void setclickButton(bool click) override;
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;

};

class SunflowerButton : public Card {
public:
	Texture buttonTexture;
	Sprite buttonSprite;
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;
	void setclickButton(bool click) override;

};


class WallnutButton : public Card {
public:
	void setclickButton(bool click) override;
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;

};

class CherryBombButton : public Card {
public:
	void setclickButton(bool click) override;
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;
};
class SnowPeaButton : public Card {
public:
	void setclickButton(bool click) override;
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;
};


class sunbutton : public Card {
public:
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;
	void setclickButton(bool click) override;

};

class exitCard : public Card {
public:
	bool clickButton() override;
	void drawButton(RenderWindow& window) override;
	string getButtonName() override;
	void setposition(Vector2f pos) override;
	bool isMousepressed(RenderWindow& window) override;
	void setclickButton(bool click) override;
};