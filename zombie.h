
#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class zombie {
protected:
	bool movement[60];
	int health;
	int speed;
	int x, y;
	bool isAlive;
	bool isAttacking;
	bool plantInRange;
	sf::Texture zombieTexture;
	sf::Sprite zombieSprite;
	Clock clock;
	bool stop;
public:
	void drawZombie(RenderWindow& window);
	void moveZombie(int num);
	void setposition(Vector2f pos);
	bool isMousepressed(RenderWindow& window);
	void setzombiexy(int x, int y);
	zombie();
	void setvalues(int health, int x, int y, bool isAlive);
	int getHealth();
	bool zombieGetIsAlive() { return isAlive; }
	bool getIsAttacking() { return isAttacking; }
	int getzombiex() { return x; }
	int getzombiey() { return y; }
	void setzombieAlive(bool alive) { isAlive = alive; }
	
	int zombieGetHealth() { return health; }
	void zombieSetHealth(int health) { this->health = health; }
	void zombieSetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	sf::FloatRect getGlobalBounds() const {
		return zombieSprite.getGlobalBounds();
	}
	void setx(int z) { x = x+z; }
	void setzombieAttacking(bool isAttacking) { this->isAttacking = isAttacking; }
	void setstop(bool stop);
	void  setstoptrue();
	
};
class normalZombie : public zombie {
public:
	normalZombie();

};
class footballZombie : public zombie {
public:
	footballZombie();

};
class flyingZombie : public zombie {
public:
	flyingZombie();
};
class dancingZombie : public zombie {
public:
	dancingZombie();
};

class DolphinRiderZombie : public zombie {
public:
	DolphinRiderZombie();
};
	
#endif // !ZOMBIE_H_