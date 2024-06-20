#include<iostream>
#include<SFML/Graphics.hpp>
#include"MainGame.h"
#include<fstream>
#include <cstdio>
#include <filesystem> 
using namespace std;
using namespace sf;

bool mainGame::getgameovermain()
{
	return level[levelnumber]->getgameover();
}
void mainGame::movegame(RenderWindow& window,Event event)
{
	currency.setMenuButton(window, to_string(level[levelnumber]->getpesea()), -50, 100, 20);
	currency.Draw_button(window);
	level[levelnumber]->drawSunandMove(window);
	level[levelnumber]->drawLevel(window, 1, event);
	
}

mainGame::mainGame() {
	level[0] = new level1();
	saveGame = false;
	peashoooternum = 0;
	snowpeanum = 0;
	sunflowernum = 0;
	wallnutnum = 0;
	repeaternum = 0;
	cherrybombnum = 0;
	cardplant = false;
	levelnumber = 0;

	for (int i = 0; i < 3; i++)
	{
		highScore[i] = 0;
		highestScore[i] = "Player";
	}

}

void mainGame::drawgrid(RenderWindow& window) {
	level[0]->drawGrid(window);
	
}


void mainGame::levelupdate(RenderWindow& window)
{
	if (level[levelnumber]->checklevel())
	{
		for (int i = 0; i < 50; i++)
		{
			level[levelnumber]->zombiefactory.zom[i] = nullptr;
		}
		levelnumber++;
		if (levelnumber == 1)
		{
			cout << "going in level 2\n";
			level[levelnumber] = new level2();
			cout << "level 2 created\n";
			level[levelnumber]->zomDiecheck = 0;
			peashoooternum = 0;
			snowpeanum = 0;
			sunflowernum = 0;
			wallnutnum = 0;
			repeaternum = 0;
			cherrybombnum = 0;
			cardplant = false;
			level[levelnumber]->setzombiecount(20);
			level[levelnumber]->drawGrid(window);
			level[levelnumber]->setlives(5);

		}
		if (levelnumber == 2)
		{
			cout << "going in level 3\n";
			level[levelnumber] = new level3();
			level[levelnumber]->zomDiecheck = 0;
			peashoooternum = 0;
			snowpeanum = 0;
			sunflowernum = 0;
			wallnutnum = 0;
			repeaternum = 0;
			cherrybombnum = 0;
			cardplant = false;
			level[levelnumber]->drawGrid(window);
			level[levelnumber]->setlives(5);
		}
		if (levelnumber == 3)
		{
			cout << "Ging in level 4\n";
			level[levelnumber] = new level4();
			level[levelnumber]->zomDiecheck = 0;
			peashoooternum = 0;
			snowpeanum = 0;
			sunflowernum = 0;
			wallnutnum = 0;
			repeaternum = 0;
			cherrybombnum = 0;
			cardplant = false;
			level[levelnumber]->drawGrid(window);
			level[levelnumber]->setlives(5);
		}
		if (levelnumber == 4)
		{
			level[levelnumber] = new level5();
			level[levelnumber]->zomDiecheck = 0;
			peashoooternum = 0;
			snowpeanum = 0;
			sunflowernum = 0;
			wallnutnum = 0;
			repeaternum = 0;
			cherrybombnum = 0;
			cardplant = false;
			level[levelnumber]->drawGrid(window);
			level[levelnumber]->setlives(5);
		}
	}

}
void mainGame::cardcheck(RenderWindow& window)
{
	if (level[levelnumber]->card[8]->isMousepressed(window) == true)
	{
		level[levelnumber]->card[8]->setclickButton(true);
		level[levelnumber]->card[1]->setclickButton(false);
		level[levelnumber]->card[2]->setclickButton(false);
		level[levelnumber]->card[3]->setclickButton(false);
		level[levelnumber]->card[4]->setclickButton(false);
		level[levelnumber]->card[5]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);
		level[levelnumber]->card[7]->setclickButton(false);

	}


	if (level[levelnumber]->card[7]->isMousepressed(window) == true)
	{
		cout << "\n\ncard 7 is pressed\n\n";
	// 	cout << "\n\nheloooooo\n\n";
		level[levelnumber]->card[7]->setclickButton(true);
		level[levelnumber]->card[1]->setclickButton(false);
		level[levelnumber]->card[2]->setclickButton(false);
		level[levelnumber]->card[3]->setclickButton(false);
		level[levelnumber]->card[4]->setclickButton(false);
		level[levelnumber]->card[5]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);

	}
	if (level[levelnumber]->card[1]->isMousepressed(window) == true)
	{
		level[levelnumber]->card[1]->setclickButton(true);
		cout << "Button is pressed" << "Card 111111111111111111" << endl;
		level[levelnumber]->card[7]->setclickButton(false);
		cout << "Save Game is true\n";
		level[levelnumber]->card[2]->setclickButton(false);
		level[levelnumber]->card[3]->setclickButton(false);
		level[levelnumber]->card[4]->setclickButton(false);
		level[levelnumber]->card[5]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);
	}
	if (level[levelnumber]->card[2]->isMousepressed(window) == true)
	{
		level[levelnumber]->card[2]->setclickButton(true);
		level[levelnumber]->card[7]->setclickButton(false);
		level[levelnumber]->card[1]->setclickButton(false);
		level[levelnumber]->card[3]->setclickButton(false);
		level[levelnumber]->card[4]->setclickButton(false);
		level[levelnumber]->card[5]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);
	}
	if (level[levelnumber]->card[3]->isMousepressed(window) == true)
	{
		level[levelnumber]->card[3]->setclickButton(true);
		//cout << "Button is pressed" << endl;
		//
		level[levelnumber]->card[7]->setclickButton(false);
		//cout << "button is   " << level[levelnumber]->card[0]->clickButton() << endl;

		level[levelnumber]->card[1]->setclickButton(false);
		level[levelnumber]->card[2]->setclickButton(false);
		level[levelnumber]->card[4]->setclickButton(false);
		level[levelnumber]->card[5]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);
	}
	if (level[levelnumber]->card[4]->isMousepressed(window) == true)
	{
		level[levelnumber]->card[4]->setclickButton(true);
		//cout << "Button is pressed" << endl;
		level[levelnumber]->card[7]->setclickButton(false);
		//cout << "button is   " << level[levelnumber]->card[0]->clickButton() << endl;
		saveGame = true;
		level[levelnumber]->card[1]->setclickButton(false);
		level[levelnumber]->card[2]->setclickButton(false);
		level[levelnumber]->card[3]->setclickButton(false);
		level[levelnumber]->card[5]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);
	}
	if (level[levelnumber]->card[5]->isMousepressed(window) == true)
	{
		level[levelnumber]->card[5]->setclickButton(true);
		//cout << "Button is pressed" << endl;
		//cout << "button is   " << 5 << endl;
		level[levelnumber]->card[7]->setclickButton(false);
		level[levelnumber]->card[1]->setclickButton(false);
		level[levelnumber]->card[2]->setclickButton(false);
		level[levelnumber]->card[4]->setclickButton(false);
		level[levelnumber]->card[3]->setclickButton(false);
		level[levelnumber]->card[6]->setclickButton(false);
	}
}
void mainGame:: sunclick(RenderWindow& window)
{
	if (level[levelnumber]->sun.isMousepressed(window))
	{
		if (level[levelnumber]->sun.getexists() == true)
		{
			level[levelnumber]->sun.setexists(false);
			level[levelnumber]->pesea += 100;

		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (level[levelnumber]->plantfactory.sunflower[i].isMousepressed(window)  && level[levelnumber]->plantfactory.sunflower[i].getIsAlive()==true)
		{
			level[levelnumber]->plantfactory.sunflower[i].Sun::setcheck(false);
			level[levelnumber]->plantfactory.sunflower[i].setSunflower(true);
			level[levelnumber]->pesea += 50;
		}

	}
}
void mainGame::createplant(RenderWindow& window)
{
	if (level[levelnumber]->card[3]->clickButton() == true)
	{
		cout << "plant card " << 0 << endl;
		if (wallnutnum < level[levelnumber]->PlantCount)
			if (level[levelnumber]->getpesea() >= 50)
			{
				if (level[levelnumber]->isMouseOver(window) == true)
				{

					if (level[levelnumber]->plantfactory.wallnut[wallnutnum].getIsAlive() == false && level[levelnumber]->PlantCount > wallnutnum)
					{
						level[levelnumber]->plantfactory.wallnut[wallnutnum].setvalues(100, 100, 10, true, false, false, level[levelnumber]->getx() + 40, level[levelnumber]->gety() + 30);

						cout << "Plant is created" << endl;
						cout << level[levelnumber]->getx() << level[levelnumber]->gety() << endl;
						cout << wallnutnum << endl;
						level[levelnumber]->card[3]->setclickButton(false);
						level[levelnumber]->plantfactory.wallnut[wallnutnum].setIsAlive(true);
						// Saving content in file
						level[levelnumber]->setwallnummove(wallnutnum, true);


						wallnutnum++;

						int pesea = level[levelnumber]->getpesea();
						pesea -= 50;
						level[levelnumber]->setpesea(pesea);

					}


				}
			}
	}

	//////////////////////////////////repeater////////////////////////////

	if (level[levelnumber]->card[5]->clickButton() == true )
	{
		cout << "plant card " << 0 << endl;
		if (repeaternum < level[levelnumber]->PlantCount)
			if (level[levelnumber]->getpesea() >= 200)
			{
				if (level[levelnumber]->isMouseOver(window) == true)
				{

					if (level[levelnumber]->plantfactory.repeater[repeaternum].getIsAlive() == false && level[levelnumber]->PlantCount > repeaternum)
					{
						level[levelnumber]->plantfactory.repeater[repeaternum].setvalues(100, 100, 10, true, false, false, level[levelnumber]->getx() + 30, level[levelnumber]->gety());
						cout << "Plant is created" << endl;
						cout << level[levelnumber]->getx() << level[levelnumber]->gety() << endl;
						cout << repeaternum << endl;
						level[levelnumber]->card[4]->setclickButton(false);
						level[levelnumber]->plantfactory.repeater[repeaternum].setIsAlive(true);


						repeaternum++;

					}

					int pesea = level[levelnumber]->getpesea();
					pesea -= 200;
					level[levelnumber]->setpesea(pesea);
				}
			}
	}




	if (level[levelnumber]->card[7]->clickButton() == true )
	{
		cout << "plant card                    sunflowerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr " << 0 << endl;
		if (sunflowernum < level[levelnumber]->PlantCount)
			if (level[levelnumber]->getpesea() >= 50)
			{
				if (level[levelnumber]->isMouseOver(window) == true)
				{

					if (level[levelnumber]->plantfactory.sunflower[sunflowernum].getIsAlive() == false && level[levelnumber]->PlantCount > sunflowernum)
					{
						cout << "plant number  " << sunflowernum << "     x   and y are  " << level[levelnumber]->getx() << "  " << level[levelnumber]->gety() << endl;

						level[levelnumber]->plantfactory.sunflower[sunflowernum].setvalues(100, 100, 10, true, false, false, level[levelnumber]->getx()+32, level[levelnumber]->gety());
						cout << "Plant is created" << endl;
						cout << level[levelnumber]->getx() << level[levelnumber]->gety() << endl;
						cout << sunflowernum << endl;
							level[levelnumber]->card[7]->setclickButton(false);
						level[levelnumber]->plantfactory.sunflower[sunflowernum].setIsAlive(true);




						sunflowernum++;
						int pesea = level[levelnumber]->getpesea();
						pesea -= 50;
						level[levelnumber]->setpesea(pesea);
					}

				}
			
			}
	}

	//////////////////////////

	if (level[levelnumber]->card[2]->clickButton() == true)
	{
		if (snowpeanum < level[levelnumber]->PlantCount)
			if (level[levelnumber]->getpesea() >= 100)
			{

				if (level[levelnumber]->isMouseOver(window) == true)
				{
					if (level[levelnumber]->plantfactory.snowpea[snowpeanum].getIsAlive() == false && level[levelnumber]->PlantCount > snowpeanum)
					{
						level[levelnumber]->plantfactory.snowpea[snowpeanum].setvalues(100, 100, 10, true, false, false, level[levelnumber]->getx(), level[levelnumber]->gety());
						cout << "Plant is created" << endl;
						cout << level[levelnumber]->getx() << level[levelnumber]->gety() << endl;
						cout << snowpeanum << endl;
						level[levelnumber]->card[2]->setclickButton(false);
						level[levelnumber]->plantfactory.snowpea[snowpeanum].setIsAlive(true);



						snowpeanum++;
					
						int pesea = level[levelnumber]->getpesea();
						pesea -= 100;
						level[levelnumber]->setpesea(pesea);
					}

					
				}
			}
	}
	///////////////////////////

	for (int i = 0; i < 3; i++)
	{
		if (highScore[i] < level[levelnumber]->score)
		{
			highestScore[i] = "Player";
			highScore[i] = level[levelnumber]->score;
		}
	}

	if (level[levelnumber]->card[1]->clickButton() == true)
	{
		cout << "Card is true    peashoter  \n";
		if (peashoooternum < level[levelnumber]->PlantCount)
		{
			if (level[levelnumber]->getpesea() >= 50)
			{

			if (level[levelnumber]->isMouseOver(window) == true)
			{
				cout << "peashooter number is  " << peashoooternum << endl;
				cout << "Mouse is over\n";
				

					if (level[levelnumber]->plantfactory.peashooter[peashoooternum].getIsAlive() == false && peashoooternum < level[levelnumber]->PlantCount)
					{
						cout << "Peashooter is going creat\n";
						level[levelnumber]->plantfactory.peashooter[peashoooternum].setvalues(100, 100, 10, true, false, false, level[levelnumber]->getx(), level[levelnumber]->gety());
						cout << "Plant is created" << endl;
						cout << level[levelnumber]->getx() << "   " << level[levelnumber]->gety() << endl;
						cout << peashoooternum << endl;
						level[levelnumber]->card[1]->setclickButton(false);
						level[levelnumber]->plantfactory.peashooter[peashoooternum].setIsAlive(true);
						cout << "Peashooter is created\n " << level[levelnumber]->plantfactory.peashooter[peashoooternum].bulletgetexists();



						peashoooternum++;
						int pesea = level[levelnumber]->getpesea();
						pesea -= 100;
						level[levelnumber]->setpesea(pesea);
					}

				

				}
			}
		}
	}
	///////////////////////////		cherries		////////////////////////

	if (level[levelnumber]->card[4]->clickButton() == true )
	{
		if (cherrybombnum < level[levelnumber]->PlantCount)
			if (level[levelnumber]->getpesea() >= 150)
			{

				if (level[levelnumber]->isMouseOver(window) == true)
				{
				cout << "going to crwat cherry bomb\n";
				if (level[levelnumber]->plantfactory.cherrybomb[cherrybombnum].getIsAlive() == false && cherrybombnum < level[levelnumber]->PlantCount)
				{
					level[levelnumber]->plantfactory.cherrybomb[cherrybombnum].setvalues(100, 100, 10, true, false, false, level[levelnumber]->getx()+32, level[levelnumber]->gety());
					cout << "cherry bom position   " << level[levelnumber]->plantfactory.cherrybomb[cherrybombnum].getx() << "  " << level[levelnumber]->plantfactory.cherrybomb[cherrybombnum].gety() << endl;
					cout << "Plant is created" << endl;
					//cout << level[levelnumber]->getx() << level[levelnumber]->gety() << endl;
					cout << cherrybombnum << endl;
					level[levelnumber]->card[4]->setclickButton(false);
					level[levelnumber]->plantfactory.cherrybomb[cherrybombnum].setIsAlive(true);
					cherrybombnum++;

					int pesea = level[levelnumber]->getpesea();
					pesea -= 150;
					level[levelnumber]->setpesea(pesea);
				}

				
			}
		}
	}

	
}
/// <summary>
/// ///////////////////////////////Read from file///////////////////////////
/// function for reading from file
/// </summary>

void mainGame::readfromfile() {
	ifstream file;
	file.open("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Resumelevel.txt");
	if (file.is_open()) {
		file >> peashoooternum;
		file >> snowpeanum;
		file >> sunflowernum;
		file >> wallnutnum;
		file >> repeaternum;
		file >> cherrybombnum;
		file >> cardplant;
		file >> levelnumber;
		int plantNum = 0;
		file >> plantNum;
		int zommun = 0;
		file >> zommun;
		int peasea;
		file >> peasea;
		int lives;
		file >> lives;

		level[levelnumber]->setlives(lives);

		for (int i = 0; i < 3; i++)
		{
			string name;
			int a;
			file >> name >> a;

			highestScore[i] = name;
			highScore[i] = a;
		}


		if (levelnumber == 1)
		{
			level[levelnumber] = new level1();
		}
		else if (levelnumber == 2)
		{
			level[levelnumber] = new level2();
		}
		else if (levelnumber == 3)
		{
			level[levelnumber] = new level3();
		}
		else if (levelnumber == 4)
		{
			level[levelnumber] = new level4();
		}
		else if (levelnumber == 5)
		{
			level[levelnumber] = new level5();
		}

		level[levelnumber]->setplantcount(plantNum);
		level[levelnumber]->setzombiecount(zommun);

		for (int i = 0; i < wallnutnum; i++)
		{
			int health, x, y;
			bool isAlive;

			file >> health >> x >> y >> isAlive;
			level[levelnumber]->plantfactory.wallnut[i].setvalues(health, 100, 10, isAlive, false, false, x, y);
		}
		// Repeaternumber
		for (int i = 0; i < repeaternum; i++)
		{
			int health, x, y;
			bool isAlive;
			file >> health >> x >> y >> isAlive;

			level[levelnumber]->plantfactory.repeater[i].setvalues(health, 100, 10, isAlive, false, false, x, y);
		}
		//   Sunflower number
		for (int i = 0; i < sunflowernum; i++)
		{
			int health, x, y;
			bool isAlive;
			file >> health >> x >> y >> isAlive;
			level[levelnumber]->plantfactory.sunflower[i].setvalues(health, 100, 10, isAlive, false, false, x, y);
			
		}
		// snowpea number
		for (int i = 0; i < snowpeanum; i++)
		{
			int health, x, y;
			bool isAlive;
			file >> health >> x >> y >> isAlive;
			level[levelnumber]->plantfactory.snowpea[i].setvalues(health, 100, 10, isAlive, false, false, x, y);
		}
		//   Peashooter number
		for (int i = 0; i < peashoooternum; i++)
		{
			int health, x, y;
			bool isAlive;
			file >> health >> x >> y >> isAlive;
			level[levelnumber]->plantfactory.peashooter[i].setvalues(health, 100, 10, isAlive, false, false, x, y);
		}
		//  cherrybomb number
		for (int i = 0; i < cherrybombnum; i++)
		{
			int health, x, y;
			bool isAlive;
			file >> health >> x >> y >> isAlive;
			level[levelnumber]->plantfactory.cherrybomb[i].setvalues(health, 100, 10, isAlive, false, false, x, y);
		}

		for (int i = 0; i < level[levelnumber]->getzombiecount(); i++)
		{
			int health, x, y;
			bool isAlive;
			file >> x >> y >> health >> isAlive;
			if (level[levelnumber]->zombiefactory.zom[i] != nullptr)
				level[levelnumber]->zombiefactory.zom[i]->setvalues(health, x, y, isAlive);
		}
		file.close();
	}
	else {
		cout << "Error opening file" << endl;
	}
}

/// <summary>
/// ///////////////////////////////Save Game///////////////////////////
/// Function for saving the gamw
/// <returns></returns>
bool mainGame::savegame(bool save)
{
	std::string filename = "C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Resumelevel.txt";

	//std::string filename = "C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Resumelevel.txt";

	// Check if the file exists using ifstream
	std::ifstream ifile(filename);
	if (ifile) { // If the file exists
		// Close the ifstream
		ifile.close();
		// Delete the file
		if (std::remove(filename.c_str()) != 0) {
			std::cerr << "Error deleting file\n";
			// Handle error if necessary
		}
		else {
			std::cout << "File deleted successfully\n";
		}
	}
	

	if(true)
	{
		ofstream file;
		file.open("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\Resumelevel.txt");
		cout << "File is opened\n";
		file << peashoooternum << endl;
		file << snowpeanum << endl;
		file << sunflowernum << endl;
		file << wallnutnum << endl;
		file << repeaternum << endl;
		file << cherrybombnum << endl;
		file << cardplant << endl;
		file << levelnumber << endl;
		file << level[levelnumber]->PlantCount << endl;
		file << level[levelnumber]->getzombiecount() << endl;
		file << level[levelnumber]->getpesea() << endl;
		file << level[levelnumber]->getlives() << endl;
		
		for (int i = 0; i < 3; i++)
		{
			file << highestScore[i] << " " << highScore[i] << endl;
			
		}

		//   Wallnut number
		for (int i = 0; i < wallnutnum; i++)
		{
			
			file << level[levelnumber]->plantfactory.wallnut[i].getHealth() << " " << level[levelnumber]->plantfactory.wallnut[i].getx() << " " << level[levelnumber]->plantfactory.wallnut[i].gety() << " " << level[levelnumber]->plantfactory.wallnut[i].getIsAlive() << endl;
		}
		// Repeaternumber
		for (int i = 0; i < repeaternum; i++)
		{
			file << level[levelnumber]->plantfactory.repeater[i].getHealth() << " " << level[levelnumber]->plantfactory.repeater[i].getx() << " " << level[levelnumber]->plantfactory.repeater[i].gety() << " " << level[levelnumber]->plantfactory.repeater[i].getIsAlive() << endl;
		}
		//   Sunflower number
		for (int i = 0; i < sunflowernum; i++)
		{
			file << level[levelnumber]->plantfactory.sunflower[i].getHealth() << " " << level[levelnumber]->plantfactory.sunflower[i].plant::getx() << " " << level[levelnumber]->plantfactory.sunflower[i].plant::gety() << " " << level[levelnumber]->plantfactory.sunflower[i].getIsAlive() << endl;
		}
		// snowpea number
		for (int i = 0; i < snowpeanum; i++)
		{
			file << level[levelnumber]->plantfactory.snowpea[i].getHealth() << " " << level[levelnumber]->plantfactory.snowpea[i].plant::getx() << " " << level[levelnumber]->plantfactory.snowpea[i].plant::gety() << " " << level[levelnumber]->plantfactory.snowpea[i].getIsAlive() << endl;
		}
		//   Peashooter number
		for (int i = 0; i < peashoooternum; i++)
		{
			file << level[levelnumber]->plantfactory.peashooter[i].getHealth() << " " << level[levelnumber]->plantfactory.peashooter[i].plant::getx() << " " << level[levelnumber]->plantfactory.peashooter[i].plant::gety() << " " << level[levelnumber]->plantfactory.peashooter[i].getIsAlive() << endl;
		}
		//  cherrybomb number
		for (int i = 0; i < cherrybombnum; i++)
		{
			file << level[levelnumber]->plantfactory.cherrybomb[i].getHealth() << " " << level[levelnumber]->plantfactory.cherrybomb[i].plant::getx() << " " << level[levelnumber]->plantfactory.cherrybomb[i].plant::gety() << " " << level[levelnumber]->plantfactory.cherrybomb[i].getIsAlive() << endl;
		}

		for (int i = 0; i < level[levelnumber]->getzombiecount(); i++)
		{
			if (level[levelnumber]->zombiefactory.zom[i] != nullptr)
				file << level[levelnumber]->zombiefactory.getzombiex(i) << " " << level[levelnumber]->zombiefactory.getzombiey(i) << " " << level[levelnumber]->zombiefactory.getzombiehealth(i) << " " << level[levelnumber]->zombiefactory.getzombieisAlive(i) << endl;
		}

		file.close();
		return true;
	}
	return false;
}

void mainGame::savehighyScore()
{
	
	ofstream file;
	file.open("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\highscore.txt");
	for (int i = 0; i < 3; i++)
	{
		file << highestScore[i][0] << " " << highestScore[i][1] << endl;
	}
	file.close();


}


void mainGame::readhighScore()
{
	ifstream file;
	file.open("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\highscore.txt");
	for (int i = 0; i < 3; i++)
	{
		file >> highestScore[i][0] >> highestScore[i][1];
	}
	file.close();
}
