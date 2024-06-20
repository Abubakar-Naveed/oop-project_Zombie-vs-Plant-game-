#include<iostream>
#include <SFML/Graphics.hpp>
#include"../Project1/ZombieFacory.h"
using namespace std;
using namespace sf;
void ZombieFactory::level1zombie() {
	
	cout << "We are in level1 zombie \n";
	for (int i = 0; i < 10; i++)
	{
		zom[i] = new normalZombie();
	}
	for (int i = 0,j=0; i < 10; i++,j++) {
	//	zom[i] = new normalZombie();
		if (j == 5)
		{
			j = 0;
		}
		zom[i]->setvalues(100,  (32*40) +rand() % 40 * 32 , 96+ j * 112, true);
	}
}




void ZombieFactory::level2zombie() {
	
	//delete[]zom;
	cout << "We are in level2 zombie \n";
	for (int i = 0,j=0; i < 10; i++,j++) {
		zom[i] = new normalZombie();
		cout << "zombie created\n";
		if (j < 5)
		{
			zom[i]->setvalues(100, (32 * 40) + rand() % 40 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(100, (32 * 50) + rand() % 50 * 32, 96 +( j-5) * 112, true);
		}
		
		cout << "zombie created\n";
		
	}
	for (int i = 10,j=0; i < 20; j++,i++) {
	zom[i] = new footballZombie();
		if (j < 5)
		{
			zom[i]->setvalues(150, (32 * 70) + rand() % 50 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(150, (32 * 80) + rand() % 50 * 32, 96 + (j - 5) * 112, true);
		}
		
	}
	cout << "Initialised football zombie\n";

	for (int i = 20, j = 0; i < 30; i++, j++) {
		zom[i] = new DolphinRiderZombie();
		if (j <5)
		{
			zom[i]->setvalues(200, (32 * 100) + rand() % 60 * 32, 96 + j * 112, true);
		
		}
		else
		{
			zom[i]->setvalues(200, (32 * 110) + rand() % 60 * 32, 96 + (j-5) * 112, true);
		}
		cout << "zombie created\n";

	}

}
void ZombieFactory::level3zombie() {
	
	//delete[]zom;
	cout << "I am in zombie\n";
	for (int i = 0,j=0; i < 10; i++,j++) {
		zom[i] = new normalZombie();
		if (j <5)
		{
			zom[i]->setvalues(100, (32 * 40) + rand() % 40 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(100, (32 * 50) + rand() % 50 * 32, 96 + (j-5) * 112, true);
		}
		cout << "zombie created\n";
	}
	for (int i = 10,j=0; i < 20;j++, i++) {
		zom[i] = new footballZombie();
		if (j< 5)
		{
			zom[i]->setvalues(150, (32 * 80) + rand() % 50 * 32, 112 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(150, (32 * 90) + rand() % 50 * 32, 112 + (j-5) * 112, true);
		}
		
		cout << "zombie created\n";
	}
	for (int i = 30,j=0; i < 40; i++,j++) {
		zom[i] = new flyingZombie();
		if (j <5)
		{
			zom[i]->setvalues(100, (32 * 70) + rand() % 50 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(100, (32 * 80) + rand() % 60 * 32, 96 + (j-5) * 112, true);
		}
		
		cout << "zombie created\n";
	}
	for (int i = 20, j = 0; i < 30; i++, j++) {
		zom[i] = new DolphinRiderZombie();
		if (j < 5)
		{
			zom[i]->setvalues(200, (32 * 70) + rand() % 60 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(200, (32 * 80) + rand() % 60 * 32, 96 + (j - 5) * 112, true);
		}
		cout << "zombie created\n";

	}
	
}
void ZombieFactory::level4zombie() {
	
	//delete[]zom;
	for (int i = 0,j=0; i < 10; i++,j++) {
	zom[i] = new normalZombie();
	
		if (j < 5)
		{
			zom[i]->setvalues(100, (32 * 30) + rand() % 40 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(100, (32 * 50) + rand() % 40 * 32, 96 + (j -5)* 112, true);
		}
	
	
	
	}
	for (int i = 10,j=0; i < 20; i++,j++) {
	zom[i] = new footballZombie();
		if (j == 5)
		{
			zom[i]->setvalues(200, (32 * 60) + rand() % 40 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(200, (32 * 90) + rand() % 50 * 32, 96 + (j - 5) * 112, true);
		}
		
	}
	for (int i = 30,j=0; i < 40; i++,j++) {
		zom[i] = new flyingZombie();
		if (j < 5)
		{
			zom[i]->setvalues(100, (32 * 60) + rand() % 50 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(100, (32 * 120) + rand() % 50 * 32, 96 + (j - 5) * 112, true);
		}
		
	}
	for (int i = 40,j=0; i < 50; i++,j++) {
		zom[i] = new dancingZombie();
		if (j < 5)
		{
			zom[i]->setvalues(100, (32 * 80) + rand() % 60 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(100, (32 * 130) + rand() % 60 * 32, 96 + (j - 5) * 112, true);
		}
	}
	for (int i = 20,j=0; i < 30; j++,i++)
	{
		zom[i] = new DolphinRiderZombie();
		if (j < 5)
		{
			zom[i]->setvalues(100, (32 * 90) + rand() % 50 * 32, 96 + j * 112, true);

		}
		else
		{
			zom[i]->setvalues(100, (32 * 150) + rand() % 50 * 32, 96 + (j - 5) * 112, true);
		}
	}


}
void ZombieFactory::level5zombie() {
	
	//delete[]zom;
	for (int i = 0,j=0; i < 10; j++,i++) {
		zom[i] = new normalZombie();
		if (j< 5)
		{
			zom[i]->setvalues(100, (32 * 40) + rand() % 40 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(100, (32 * 40) + rand() % 50 * 32, 96 + (j - 5) * 112, true);
		}
		
	}

	for (int i = 10,j=0; i < 20; j++,i++) {
		zom[i] = new footballZombie();
		if (j <5)
		{
			zom[i]->setvalues(150, (32 * 50) + rand() % 50 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(150, (32 * 60) + rand() % 60 * 32, 96 + (j - 5) * 112, true);
		}
	}
	for (int i = 20,j=0; i < 30; j++,i++) {
		zom[i] = new flyingZombie();
		if (j <5)
		{
			zom[i]->setvalues(100, (32 * 50) + rand() % 50 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(100, (32 * 70) + rand() % 60 * 32, 96 + (j - 5) * 112, true);
		}

	}
	for (int i = 30,j=0; i < 40; j++,i++) {
		zom[i] = new dancingZombie();
		if (j< 5)
		{
			zom[i]->setvalues(100, (32 * 40) + rand() % 60 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(100, (32 * 70) + rand() % 60 * 32, 96 + (j - 5) * 112, true);
		}

	}
	for (int i = 40,j=0; i < 50; i++,j++) {
		zom[i] = new DolphinRiderZombie();
		if (j < 5)
		{
			zom[i]->setvalues(100, (32 * 60) + rand() % 70 * 32, 96 + j * 112, true);
		}
		else
		{
			zom[i]->setvalues(100, (32 * 90) + rand() % 70 * 32, 96 + (j - 5) * 112, true);	
		}
	}
}