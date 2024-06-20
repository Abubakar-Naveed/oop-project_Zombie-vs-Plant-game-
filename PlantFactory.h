
#ifndef PLANTFACTORY_H_
#define PLANTFACTORY_H_
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Plant.h"
using namespace std;
using namespace sf;

class PlantFactory : public plant{
public:
	
	
	Sunflower sunflower[15];
	Peashooter peashooter[15];
	SnowPea snowpea[15];
	Wallnut wallnut[15];
	CherryBomb cherrybomb[15];
	Repeater repeater[15];
	//plant *Plant[50];
	PlantFactory()
	{

	}

};



#endif // PLANFACTORY_H_