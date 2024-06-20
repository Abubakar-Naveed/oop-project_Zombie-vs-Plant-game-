#include<iostream>
using namespace std;
#include"levels.h"
#include <SFML/Graphics.hpp>
using  namespace sf;

level2::level2() {
	//zom = new zombie[20];
	
	zombiefactory.level2zombie();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			boxcheck[i][j] = false;

		}
	}
	lives = 5;
	ZombieCount = 30;
	PlantCount = 15;
}

level3::level3() {
	//zom = new zombie[20];
	cout << "going in zombie factory\n";
	zombiefactory.level3zombie();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			boxcheck[i][j] = false;

		}
	}
	lives = 5;
	ZombieCount = 50;
	PlantCount = 15;
}

level4::level4() {
	//zom = new zombie[20];

	zombiefactory.level4zombie();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			boxcheck[i][j] = false;

		}
	}
	lives = 5;
	ZombieCount = 50;
	PlantCount = 15;

}

level5::level5()
{
	//zom = new zombie[20];
	zombiefactory.level5zombie();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			boxcheck[i][j] = false;

		}
	}
	ZombieCount = 50;
	lives = 5;
	PlantCount = 15;

}