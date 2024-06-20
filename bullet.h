#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class bullet {
protected:
	int damage;
	int x, y;
	bool exists;
	int speed;
	bool check;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	
public:
	Clock clock;
	bullet();
	bullet(int damage);
	bool getcheck() { 
		//cout << "Check is : " << this->check << "\n";
		return check; }
	void setcheck(bool Paracheck) { this->check = Paracheck;
	//cout << "Check is now : "<< this->check;
	}
	void setdamage(int damage);
	int getdamage();
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	int getx() { return x; }
	int gety() { return y; }
	void drawBullet(RenderWindow& window);
	void setposition(Vector2f pos);
	void moveBullet();
	bool isMousepressed(RenderWindow& window);
	void bulletsetexists( bool exists);
	bool bulletgetexists() { return exists; }
	float getWidth() const {
		// Assuming bulletSprite is the sprite representing the bullet
		return bulletSprite.getGlobalBounds().width;
	}
	float getHeight() const {
		return bulletSprite.getGlobalBounds().height;
	}
	FloatRect getLocalBounds() {
		return bulletSprite.getLocalBounds();

	}
};
class PeaBullet : public bullet {
private:
	
public:
	PeaBullet();

};
class SnowBullet : public bullet {
public:
	SnowBullet();
};

class RepeaterBullet : public bullet {
protected:
	

public:
	RepeaterBullet();


};