
#ifndef ZOMBIEFACTORY_H_
#define ZOMBIEFACTORY_H_
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"zombie.h"
using namespace std;
using namespace sf;

class ZombieFactory {
public:
	//SimplyZombie simplyzombie[10];
	
	normalZombie normalzombie[10];
	flyingZombie flyingzombie[10];
	DolphinRiderZombie dolphinriderzombie[10];
	dancingZombie dancingzombie[10];
	footballZombie footballzombie[10];
	zombie* zom[50];

	int getzombiex(int i) { return zom[i]->getzombiex(); }
	int getzombiey(int i) { return zom[i]->getzombiey(); }
	int getzombiehealth(int i) { return zom[i]->getHealth(); }
	bool getzombieisAlive(int i) { return zom[i]->zombieGetIsAlive(); }
	bool getzombieisAttacking(int i) { return zom[i]->getIsAttacking(); }

	void setzombieAlive(int i, bool alive) { zom[i]->setzombieAlive(alive); }
	void setzombieAttacking(int i, bool isAttacking) { zom[i]->setzombieAttacking(isAttacking); }
	void setzombieHealth(int i, int health) { zom[i]->zombieSetHealth(health); }
	void setzombieposition(int i, Vector2f pos) { zom[i]->setposition(pos); }
	void setzombievalues(int i, int health, int x, int y, bool isAlive) { zom[i]->setvalues(health, x, y, isAlive); }
	//void drawzombie(int i, RenderWindow& window) { zom[i]->drawZombie(window); }


	ZombieFactory() {
		
	}
	void level1zombie();
	void distorlevel1();
	void level2zombie();
	void distorlevel2();
	void level3zombie();
	void distorlevel3();
	void level4zombie();
	void distorlevel4();
	void level5zombie();
	void distorlevel5();

};


#endif // !ZOMBIEFACTORY_H_