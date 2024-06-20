#include<iostream>
#include <SFML/Graphics.hpp>
#include"Levels.h"


using namespace std;
using namespace sf;
int levels::getlives()
{
	return lives;
}
void levels::setlives(int l)
{
	lives = l;
}
bool levels::getgameover()
{
	return gameover;
}

level1::level1() {

	
	lives = 5;
	levelnum = 0;
	ZombieCount = 10;
	PlantCount = 15;
	std::cout << "Level1 constructor\n";
	zombiefactory.level1zombie();
	gameover = false;
}



levels::~levels() {
	delete card; // Deallocate memory
	delete peashooterbutton;
	delete sunflowerbutton;
	delete wallnutbutton;
	delete repeaterbutton;
	delete cherrybombbutton;
	delete snowpeabutton;
	delete exitcard;
	//delete chomperbutton;
	delete sunn;
	
	zombiebool = false;
	//
	// 
	// delete card[0];
	//delete card[1];
	delete card[2];
	delete card[3];
	delete card[4];
	delete card[5];
	//delete card[6];
	//delete card[7];
}

void levels::drawLevel(RenderWindow& window, int levelnum,Event e) {
	
		
		
		
		card[1]->drawButton(window);
		card[2]->drawButton(window);
		card[3]->drawButton(window);
		card[4]->drawButton(window);
		card[5]->drawButton(window);
		//card[6]->drawButton(window);
		card[7]->drawButton(window);
	


		
		
		for (int i = 0; i < 5; i++)
		{
			carr->drawCar(window,i);
	
			if (carr->getx(i) >1200)
			{
				carr->setexists(i,false);
			}
		}
		
		if (lives == 0)
		{
			gameover = true;
			return;
		}

		


		for (int j = 0; j < ZombieCount; j++)
		{

			if (zombiefactory.zom[j] != nullptr)
			{
				if (zombiefactory.zom[j]->zombieGetIsAlive() == true)
				{
					//cout << "haha\n";
					if (zombiefactory.zom[j]->getzombiex() < 200)
					{
						cout << "hello\n";
						// 96 + j * 112
						for (int i = 0; i < 5; i++)
						{
							if ((zombiefactory.zom[j]->getzombiey() == carr->gety(i)) && (carr->getstart(i) == false))
							{
								cout << "zom y  :  " << zombiefactory.zom[j]->getzombiey() <<"   car y "<<  carr->gety(i);
								cout << "car is starting   i   "<<i<<endl;
								carr->setstart(i, true);
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			carr->movecar(i);
		}

		for (int j = 0; j < ZombieCount; j++)
		{
			

			for (int i = 0; i < 5; i++)
			{
				if (zombiefactory.zom[j] != nullptr)
					if (carr->getx(i) >= zombiefactory.zom[j]->getzombiex() && carr->gety(i) == zombiefactory.zom[j]->getzombiey()  && zombiefactory.zom[j]->zombieGetIsAlive() == true )
					{
						zombiefactory.zom[j]->setzombieAlive(false);
						zomDiecheck++;
						cout << "Zombie killed by car\n";
					}

			}

			if (zombiefactory.zom[j] != nullptr && zombiefactory.zom[j]->zombieGetIsAlive() == true  && zombiefactory.zom[j]->getzombiex()<10)
			{
				cout << "zom out of range\n";
				zombiefactory.zom[j]->setzombieAlive(false);
				zomDiecheck++;
				lives--;
			}
		}
		
		
		/////////////////////////////Zombie bullet interaction////////////////////////////////
	
			
	
		for (int i = 0; i < PlantCount; i++) {
			if (plantfactory.peashooter[i].getIsAttacking() == true  && plantfactory.peashooter[i].getbulletcheck()==true) {
				
				for (int j = 0; j < ZombieCount; j++) {
					// Check if the zombie is alive before checking collision
					if (zombiefactory.zom[j] != nullptr)
					{
						if (zombiefactory.zom[j]->zombieGetIsAlive()) {
							float bulletX = plantfactory.peashooter[i].getBullet().getx();
							float bulletY = plantfactory.peashooter[i].getBullet().gety();
							// Get the width and height of the bullet sprite
							float bulletWidth = plantfactory.peashooter[i].getBullet().getWidth(); // Assuming getWidth() returns the width of the bullet
							float bulletHeight = plantfactory.peashooter[i].getBullet().getHeight(); // Assuming getHeight() returns the height of the bullet

							// Get the global bounds of the zombie sprite
							sf::FloatRect zombieBounds = zombiefactory.zom[j]->getGlobalBounds();
							// Calculate the position and dimensions of the zombie sprite
							float zombieX = zombieBounds.left;
							float zombieY = zombieBounds.top;
							float zombieWidth = zombieBounds.width;
							float zombieHeight = zombieBounds.height;

							//				// Define a margin for collision detection
							float collisionMargin = 0.1f; // Adjust this value as needed

							// Check if the bullet has crossed the zombie
							if (bulletX > zombieX + zombieWidth + collisionMargin || bulletX + bulletWidth < zombieX - collisionMargin ||
								bulletY > zombieY + zombieHeight + collisionMargin || bulletY + bulletHeight < zombieY - collisionMargin) {

							}
							else {
								
								plantfactory.peashooter[i].bulletSetExists(false);
								plantfactory.peashooter[i].setbulletcheck(false);
							
								zombiefactory.zom[j]->zombieSetHealth(zombiefactory.zom[j]->zombieGetHealth() - plantfactory.peashooter[i].getDoDamage());
							//	std::cout << "Zombie health \n  " << zombiefactory.zom[j]->getHealth() << endl;
								if (zombiefactory.zom[j]->zombieGetHealth() <= 0) {
									zomDiecheck++;
									/////cout << "Zombie health \n  " << zombiefactory.zom[i]->getHealth();
									zombiefactory.zom[j]->zombieSetIsAlive(false);
									score += 20;
								}
							}

						}
					}
				}
			}
		}

	
		

		//////////////////////////snowpea////////////////////////////


		for (int i = 0; i < PlantCount; i++)
		{
			if (plantfactory.snowpea[i].getIsAlive() == true)
			{
				for (int j = 0; j < ZombieCount; j++)
				{
					plantfactory.snowpea[i].drawPlant(window, plantfactory.snowpea[i].getx(), plantfactory.snowpea[i].gety());
					
					if(zombiefactory.zom[j]!=nullptr)
					if (zombiefactory.zom[j]->getzombiex() < 1000 && zombiefactory.zom[j]->getzombiey() == plantfactory.snowpea[i].plant::gety())
					{
						plantfactory.snowpea[i].attack(window);
						//zom[j]->setzombiey(snowpea[i].gety());
						plantfactory.snowpea[i].setzombieInRange(true);
						plantfactory.snowpea[i].setisAttacking(true);
					}
				}
				//snowpea[i].attack(window);
			}
		}

		for (int i = 0; i < PlantCount; i++)
		{
			if (plantfactory.peashooter[i].getIsAlive() == true)
			{
				plantfactory.peashooter[i].drawPlant(window, plantfactory.peashooter[i].plant::getx(), plantfactory.peashooter[i].plant::gety());
				
			}
		}
		for (int i = 0; i < PlantCount; i++) {
			if (plantfactory.snowpea[i].getIsAttacking() && plantfactory.snowpea[i].getbulletcheck()==true) {
				for (int j = 0; j < ZombieCount; j++) {
					if (zombiefactory.zom[j] != nullptr)
					{
						if (zombiefactory.zom[j]->zombieGetIsAlive()) {
							float bulletX = plantfactory.snowpea[i].getBullet().getx();
							float bulletY = plantfactory.snowpea[i].getBullet().gety();
							float bulletWidth = plantfactory.snowpea[i].getBullet().getWidth();
							float bulletHeight = plantfactory.snowpea[i].getBullet().getHeight();

							sf::FloatRect zombieBounds = zombiefactory.zom[j]->getGlobalBounds();
							float zombieX = zombieBounds.left;
							float zombieY = zombieBounds.top;
							float zombieWidth = zombieBounds.width;
							float zombieHeight = zombieBounds.height;

							float collisionMargin = 0.1f;

							if (bulletX > zombieX + zombieWidth + collisionMargin || bulletX + bulletWidth < zombieX - collisionMargin ||
								bulletY > zombieY + zombieHeight + collisionMargin || bulletY + bulletHeight < zombieY - collisionMargin) {

							}
							else {
								//std::cout << "Bullet hit zombie\n";
								plantfactory.snowpea[i].bulletSetExists(false);
								zombiefactory.zom[j]->setstop(true);
								zombiefactory.zom[j]->setstoptrue();

								plantfactory.snowpea[i].setbulletcheck(false);
								//cout << "Bullet is  :   " << plantfactory.snowpea[i].bullet.bulletgetexists() << "\n";
								zombiefactory.zom[j]->zombieSetHealth(zombiefactory.zom[j]->zombieGetHealth() - plantfactory.snowpea[i].getDoDamage());
							//	std::cout << "Zombie health \n  " << zombiefactory.zom[j]->getHealth() << endl;
								if (zombiefactory.zom[j]->zombieGetHealth() <= 0) {
									zomDiecheck++;
									zombiefactory.zom[j]->zombieSetIsAlive(false);
									cout << "zombie killed bybullet\n";
									score += 20;
								
								}
							}
						}
					}
				}
			}
		}

					




		////////////////////////////sunflower////////////////////////////



		for (int i = 0; i < PlantCount; i++)
		{
			if (plantfactory.sunflower->getIsAlive() == true)
			{
				
				plantfactory.sunflower[i].drawPlant(window, plantfactory.sunflower[i].plant::getx(), plantfactory.sunflower[i].plant::gety());
					
				if (plantfactory.sunflower[i].getSunflower() == false)
				{
					plantfactory.sunflower[i].Sun::setx((plantfactory.sunflower[i].plant::getx()));
					if (plantfactory.sunflower[i].Sun::gety() <= plantfactory.sunflower[i].plant::gety())
					{ 
						plantfactory.sunflower[i].Sun::setcheck(false);
					}	
					plantfactory.sunflower[i].Sun::moveSunForFlower();
					if (plantfactory.sunflower[i].Sun::gety() >= plantfactory.sunflower[i].plant::gety())
					{
						plantfactory.sunflower[i].drawSun(window);	
					}
					if(plantfactory.sunflower[i].Sun::gety()>700)
					{
						plantfactory.sunflower[i].setSunflower(true);
					}
				}
				if(plantfactory.sunflower[i].getSunflower()==true)
				{
					plantfactory.sunflower[i].Sun::sety((plantfactory.sunflower[i].plant::gety() - (16 * 4)));
					plantfactory.sunflower[i].Sun::setx(plantfactory.sunflower[i].plant::getx());
					plantfactory.sunflower[i].setSunflower(false);
				}
				
			}
		}
		

		/////////////////////////////////////////// peashooter
		

		for (int i = 0; i < PlantCount; i++)
		{
			if (plantfactory.peashooter[i].getIsAlive() == true)
			{
				//plantfactory.peashooter[i].drawPlant(window, plantfactory.peashooter[i].plant::getx(), plantfactory.peashooter[i].plant::gety());

				for (int j = 0; j < ZombieCount; j++)
				{
					if (zombiefactory.zom[j] != nullptr)
					if (zombiefactory.zom[j]->getzombiex() < 1000 && zombiefactory.zom[j]->getzombiey() == plantfactory.peashooter[i].plant::gety())
					{

						//cout << "Peashooter attacking\n";
						plantfactory.peashooter[i].setzombieInRange(true);
						plantfactory.peashooter[i].setisAttacking(true);

					}
				}
				//peashooter[i].attack(window);
				
			}
		}
	
		for (int i = 0; i < PlantCount; i++)
		{
			if (plantfactory.peashooter[i].getIsAttacking() == true)
			{	
				plantfactory.peashooter[i].attack(window);
			
			}
		}
		
		
		
		///////////////////////walnut///////////////////
	for (int i = 0; i < PlantCount; i++)
	{
		if (plantfactory.wallnut[i].getIsAlive() == true)
		{
			plantfactory.wallnut[i].drawPlant(window, plantfactory.wallnut[i].getx(), plantfactory.wallnut[i].gety());
			plantfactory.wallnut[i].moveWallnut(true);
		}
		/*for (int j = 0; i < ZombieCount; j++)
		{
			if (zombiefactory.zom[j] != nullptr )
			{
				if(zombiefactory.zom[j]->zombieGetIsAlive())
				if (zombiefactory.zom[j]->getzombiex() < 1000 && zombiefactory.zom[j]->getzombiey() == plantfactory.wallnut[i].plant::gety())
				{
					plantfactory.wallnut[i].setMove(true);
				}
			}


		}*/
	}

	
	/////////////////////////////repeater////////////////////////
	
	for (int i = 0; i < PlantCount; i++)
	{
		if (plantfactory.repeater[i].getIsAlive() == true)
		{
			plantfactory.repeater[i].drawPlant(window, plantfactory.repeater[i].getx(), plantfactory.repeater[i].gety());
			for (int j = 0; j < ZombieCount; j++)
			{
				if (zombiefactory.zom[j] != nullptr)
				if (zombiefactory.zom[j]->getzombiex() < 1000 && zombiefactory.zom[j]->getzombiey() == plantfactory.repeater[i].plant::gety())
				{
					plantfactory.repeater[i].attack(window);
					plantfactory.repeater[i].setzombieInRange(true);
					plantfactory.repeater[i].setisAttacking(true);
				}
			}

		}
	}
	for (int i = 0; i < PlantCount; i++)
	{
		if (plantfactory.repeater[i].getIsAttacking() == true)
		{
			 plantfactory.repeater[i].attack(window);
		 }
	 }


	for (int i = 0; i < PlantCount; i++)
	{
		if (plantfactory.repeater[i].getIsAttacking() == true )
		{
			for (int j = 0; j < ZombieCount; j++)
			{
				if (zombiefactory.zom[j] != nullptr)
				if (zombiefactory.zom[j]->zombieGetIsAlive()&& plantfactory.repeater[i].getbulletcheckrepeater(0) == true)
				{
					float bulletX = plantfactory.repeater[i].getBullet(0).getx();
					float bulletY = plantfactory.repeater[i].getBullet(0).gety();
					float bulletWidth = plantfactory.repeater[i].getBullet(0).getWidth();
					float bulletHeight = plantfactory.repeater[i].getBullet(0).getHeight();

					sf::FloatRect zombieBounds = zombiefactory.zom[j]->getGlobalBounds();
					float zombieX = zombieBounds.left;
					float zombieY = zombieBounds.top;
					float zombieWidth = zombieBounds.width;
					float zombieHeight = zombieBounds.height;

					float collisionMargin = 0.1f;

					if (bulletX > zombieX + zombieWidth + collisionMargin || bulletX + bulletWidth < zombieX - collisionMargin ||
						bulletY > zombieY + zombieHeight + collisionMargin || bulletY + bulletHeight < zombieY - collisionMargin) {

					}
					else {
						//std::cout << "Bullet hit zombie\n";
						plantfactory.repeater[i].setbulletcheckrepeater(false, 0);
						plantfactory.repeater[i].bulletSetExists(false,0);
						zombiefactory.zom[j]->zombieSetHealth(zombiefactory.zom[j]->zombieGetHealth() - plantfactory.repeater[i].getDoDamage());
						///std::cout << "Zombie health \n  " << zombiefactory.zom[j]->getHealth() << endl;
						if (zombiefactory.zom[j]->zombieGetHealth() <= 0) {
							zombiefactory.zom[j]->zombieSetIsAlive(false);
							cout << "zombie killed bybullet\n";

							zomDiecheck++;
							score += 20;
						}
					}
				
					
				
				
				}
				if (zombiefactory.zom[j] != nullptr)
				if (zombiefactory.zom[j]->zombieGetIsAlive() && plantfactory.repeater[i].getbulletcheckrepeater(1) == true)
				{
					float bulletX = plantfactory.repeater[i].getBullet(1).getx();
					float bulletY = plantfactory.repeater[i].getBullet(1).gety();
					float bulletWidth = plantfactory.repeater[i].getBullet(1).getWidth();
					float bulletHeight = plantfactory.repeater[i].getBullet(1).getHeight();

					sf::FloatRect zombieBounds = zombiefactory.zom[j]->getGlobalBounds();
					float zombieX = zombieBounds.left;
					float zombieY = zombieBounds.top;
					float zombieWidth = zombieBounds.width;
					float zombieHeight = zombieBounds.height;

					float collisionMargin = 0.1f;

					if (bulletX > zombieX + zombieWidth + collisionMargin || bulletX + bulletWidth < zombieX - collisionMargin ||
						bulletY > zombieY + zombieHeight + collisionMargin || bulletY + bulletHeight < zombieY - collisionMargin) {

					}
					else {
						//std::cout << "Bullet hit zombie\n";
						plantfactory.repeater[i].setbulletcheckrepeater(false, 1);
						plantfactory.repeater[i].bulletSetExists(false,1);
						//plantfactory.repeater[i].setbulletcheck(false,1);
						//cout << "Bullet is  :   " << plantfactory.snowpea[i].bullet.bulletgetexists() << "\n";
						zombiefactory.zom[j]->zombieSetHealth(zombiefactory.zom[j]->zombieGetHealth() - plantfactory.repeater[i].getDoDamage());
						//std::cout << "Zombie health \n  " << zombiefactory.zom[j]->getHealth() << endl;
						if (zombiefactory.zom[j]->zombieGetHealth() <= 0) {
							zombiefactory.zom[j]->zombieSetIsAlive(false);
							cout << "zombie killed bybullet\n";

							zomDiecheck++;
							score += 20;
						}
					}
				}
			}
		}
	}

	//////////////////////////////////////cherrybomb////////////////////////
	for (int i = 0; i < 10; i++)
	{
		if (plantfactory.cherrybomb[i].getIsAlive() == true)
		{
			
			
			bool checkk = false;
				plantfactory.cherrybomb[i].drawPlant(window, plantfactory.cherrybomb[i].getx(), plantfactory.cherrybomb[i].gety());
				cout << "cherrybomb\n";
				for (int j = 0; j < ZombieCount; j++)
				{
					if (zombiefactory.zom[j] != nullptr)
					if (((zombiefactory.zom[j]->getzombiex() <= plantfactory.cherrybomb[i].plant::getx() +64) && (zombiefactory.zom[j]->getzombiex() + 64<= plantfactory.cherrybomb[i].plant::getx())) && ( zombiefactory.zom[j]->getzombiey() +112== plantfactory.cherrybomb[i].plant::gety() || zombiefactory.zom[j]->getzombiey() -112 == plantfactory.cherrybomb[i].plant::gety()  || zombiefactory.zom[j]->getzombiey()  == plantfactory.cherrybomb[i].plant::gety()))
					{
					//	plantfactory.cherrybomb[i].setAttack(true);
						std::cout << "Now i am going to damage zombie\n";
						
						cout << "zombie killed bybullet\n";
						if (zombiefactory.zom[j]->zombieGetIsAlive() )
						zomDiecheck++;
						score += 20;
						zombiefactory.zom[j]->zombieSetIsAlive(false);
						std::cout << "Zombie killed\n";
						checkk = true;
						//zom[j]->setzombiey(snowpea[i].gety());
						//plantfactory.cherrybomb[i].setzombieInRange(true);
						//plantfactory.cherrybomb[i].setisAttacking(true);
					}
				}
				if (checkk == true)
				{
					plantfactory.cherrybomb[i].setIsAlive(false);
					std::cout << "Plant is distory\n";
				
				}

		}
	}
									///////////////////////plant vs zombie//////////////////////////////
										 ////////////////
		//////////////////////zomiess/////////////////////////////////////

						//////////////ruhan///////////////
	
	//std::cout << "  zombie zie     " << zomDiecheck << endl;
	if (zomDiecheck == ZombieCount)
	{
		
		return;

		std::cout << "Helloooooooooooooooooooo\n";
	}
	else
	{
		if (zomDiecheck == ZombieCount)
		{
			std::cout << "Level 1 is not completed\n";
		}
	
		for (int i = 0; i < ZombieCount; i++)
		{

			if (zombiefactory.zom[i] != NULL)
				if (zombiefactory.zom[i]->zombieGetIsAlive() == true)
				{
					// Your code here
					if (i == 41 || i == 43 || i == 44)
					{
						if (zombiefactory.zom[i]->getzombiex() < 600 && zombiefactory.zom[i]->getzombiex() > 590)
						{
							zombiefactory.zom[i - 34]->setvalues(100, 600, zombiefactory.zom[i]->getzombiey(), true);
							zomDiecheck--;
						}
					}

		   //RUHAN
					for (int j = 0; j < 15; j++) {
						if (zombiefactory.zom[i]->getIsAttacking() == false)
							if ((zombiefactory.zom[i]->getzombiex() > plantfactory.peashooter[j].plant::getx()) && (zombiefactory.zom[i]->getzombiex() < plantfactory.peashooter[j].plant::getx() + 32) && (zombiefactory.zom[i]->getzombiey() > plantfactory.peashooter[j].plant::gety() - 64) && (zombiefactory.zom[i]->getzombiey() < plantfactory.peashooter[j].plant::gety() + 64))
							{
								zombiefactory.zom[i]->setzombieAttacking(true);
								if (zombiefactory.zom[i]->getIsAttacking() == true) {
									if (plantfactory.peashooter[j].getHealth() > 0) {
										plantfactory.peashooter[j].sethealth(plantfactory.peashooter[j].getHealth()-10);
									}
									if (plantfactory.peashooter[j].getHealth() <= 0) {
										plantfactory.peashooter[j].setIsAlive(false);
										zombiefactory.zom[i]->setzombieAttacking(false);

									}
								}
							}
					}
					for (int j = 0; j < 15; j++) {
						if ((zombiefactory.zom[i]->getzombiex() > plantfactory.repeater[j].plant::getx()) && (zombiefactory.zom[i]->getzombiex() < plantfactory.repeater[j].plant::getx() + 32) && (zombiefactory.zom[i]->getzombiey() > plantfactory.repeater[j].plant::gety() - 64) && (zombiefactory.zom[i]->getzombiey() < plantfactory.repeater[j].plant::gety() + 64)) {

							zombiefactory.zom[i]->setzombieAttacking(true);
							if (zombiefactory.zom[i]->getIsAttacking() == true) {
								if (plantfactory.repeater[j].getHealth() > 0) {
								plantfactory.repeater[j].sethealth(plantfactory.repeater[j].getHealth() - 10);
								}
								if (plantfactory.repeater[j].getHealth() <= 0) {
									plantfactory.repeater[j].setIsAlive(false);
									zombiefactory.zom[i]->setzombieAttacking(false);

								}
							}

						}
					}
					for (int j = 0; j < 15; j++) {

						if ((zombiefactory.zom[i]->getzombiex() > plantfactory.sunflower[j].plant::getx()) && (zombiefactory.zom[i]->getzombiex() < plantfactory.sunflower[j].plant::getx() + 32) && (zombiefactory.zom[i]->getzombiey() > plantfactory.sunflower[j].plant::gety() - 64) && (zombiefactory.zom[i]->getzombiey() < plantfactory.sunflower[j].plant::gety() + 64))
						{
							zombiefactory.zom[i]->setzombieAttacking(true);
							if (zombiefactory.zom[i]->getIsAttacking() == true) {

							plantfactory.sunflower[j].sethealth(plantfactory.sunflower[j].getHealth() - 10);

								if (plantfactory.sunflower[j].getHealth() <= 0) {
									plantfactory.sunflower[j].setIsAlive(false);
									zombiefactory.zom[i]->setzombieAttacking(false);



								}
							}
						}
					}
					for (int j = 0; j < 15; j++) {
						if ((zombiefactory.zom[i]->getzombiex() > plantfactory.snowpea[j].plant::getx()) && (zombiefactory.zom[i]->getzombiex() < plantfactory.snowpea[j].plant::getx() + 32) && (zombiefactory.zom[i]->getzombiey() > plantfactory.snowpea[j].plant::gety() - 64) && (zombiefactory.zom[i]->getzombiey() < plantfactory.snowpea[j].plant::gety() + 64))
						{
							zombiefactory.zom[i]->setzombieAttacking(true);
							if (zombiefactory.zom[i]->getIsAttacking() == true) {
								if (plantfactory.snowpea[j].getHealth() > 0) {
									plantfactory.snowpea[j].sethealth(plantfactory.snowpea[j].getHealth() - 10);
								}
								if (plantfactory.snowpea[j].getHealth() <= 0) {
									plantfactory.snowpea[j].setIsAlive(false);
									zombiefactory.zom[i]->setzombieAttacking(false);

								}
							}
						}
					}
					for (int j = 0; j < 15; j++) {
						if ((zombiefactory.zom[i]->getzombiex() > plantfactory.wallnut[j].plant::getx()) && (zombiefactory.zom[i]->getzombiex() < plantfactory.wallnut[j].plant::getx() + 32) && (zombiefactory.zom[i]->getzombiey() > plantfactory.wallnut[j].plant::gety() - 64) && (zombiefactory.zom[i]->getzombiey() < plantfactory.wallnut[j].plant::gety() + 64))
						{
							zombiefactory.zom[i]->setzombieAttacking(true);
							//plantfactory.wallnut[j].setMove(true);
							if (zombiefactory.zom[i]->getIsAttacking() == true) {
								if (plantfactory.wallnut[j].getHealth() > 0) {
								plantfactory.wallnut[j].sethealth(plantfactory.wallnut[j].getHealth() - 10);
								}
								if (plantfactory.wallnut[j].getHealth() <= 0) {
									plantfactory.wallnut[j].setIsAlive(false);
									zombiefactory.zom[i]->setzombieAttacking(false);

								}
							}
						}
					}

				}
			//	cout << "zombie x  :" << zombiefactory.zom[i]->getzombiex() << "  zombie y  :" << zombiefactory.zom[i]->getzombiey() << endl;



			if (zombiefactory.zom[i] != nullptr)
			{
				if (zombiefactory.zom[i]->zombieGetIsAlive() == true && !zombiefactory.zom[i]->getIsAttacking())
				{
					//cout << "Zombie is alive\n";
					zombiefactory.zom[i]->drawZombie(window);
					zombiefactory.zom[i]->moveZombie(i);
					//	cout << "zombie x  :" << zombiefactory.zom[i]->getzombiex() << "  zombie y  :" << zombiefactory.zom[i]->getzombiey() << endl;

				}
				else if (zombiefactory.zom[i]->zombieGetIsAlive() == true && zombiefactory.zom[i]->getIsAttacking())
				{
					zombiefactory.zom[i]->drawZombie(window);
					zombiefactory.zom[i]->setx(32);
					zombiefactory.zom[i]->setzombieAttacking(false);
				}

			}

		}
		

	}		//////////////from level1 draw.........................
		

}
void levels::drawSunandMove(RenderWindow& window) {
	
	if (sun.getexists() == true)
	{
		sun.moveSun();
		sun.drawSun(window);
	}
	if (sun.getexists() == false)
	{
		sun.setexists(true);
		sun.sety(-200);
		sun.setx((rand() % 32) * 32);
	}
}




level1::~level1() {
	delete repeaterbutton;
	//delete sunflowerbutton;
	delete wallnutbutton;
	delete peashooterbutton;
	delete cherrybombbutton;
	delete snowpeabutton;
	//delete chomperbutton;
	//delete sun;
}
levels::levels() {
	//sun = nullptr;
	checklevels = true;
	carr = new carfactory;
	PlantCount = 10;	
	zomDiecheck = 0;
	check = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			boxcheck[i][j] = false;
			
		}
	}
	////////////////new edit////////////////////////
	peashooterbutton = nullptr;
	//sunflowerbutton = nullptr;
	wallnutbutton = nullptr;
	repeaterbutton = nullptr;
	cherrybombbutton = nullptr;
	snowpeabutton = nullptr;
	exitcard = nullptr;
	//chomperbutton = nullptr;
	//name = "";


/////////////////////////////////
	repeaterbutton = new RepeaterButton;
	//sunflowerbutton = new SunflowerButton;
	wallnutbutton = new WallnutButton;
	peashooterbutton = new PeashooterButton;
	cherrybombbutton = new CherryBombButton;
	snowpeabutton = new SnowPeaButton;
	sunn = new sunbutton;
	sunflowerbutton = new SunflowerButton;
	exitcard = new exitCard;
	/////////////////////////////////
	card[1] = peashooterbutton;
	card[2] = snowpeabutton;
	card[3] = wallnutbutton;
	card[4] = cherrybombbutton;
	card[5] = repeaterbutton;
	card[6] = sunn;
	card[7] = sunflowerbutton;
	card[8] = exitcard;
	levelnum = 1;
	ZombieCount = 10;



	///////////////////////     end    ////////////////////


}


void levels::drawGrid(RenderWindow& window) {
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gridbuttonTexture[i][j].loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plantfff.png");
			gridbuttonSprite[i][j].setTexture(gridbuttonTexture[i][j]);
			gridbuttonSprite[i][j].setPosition(224 + j * 80, 96 + i * 112);
			gridbuttonSprite[i][j].setScale(0.1f, 0.13f);
			//window.draw(gridbuttonSprite[i]);
		
		}
	}
}
bool levels::isMouseOver(RenderWindow& window) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			Vector2i mousePos = Mouse::getPosition(window);
			Vector2f pos = gridbuttonSprite[i][j].getPosition();
			pos.y -= 112 * 0.05f; // Adjust for scaling by 0.1f (half of the scaled height)
			//cout << "i am caleed\n";
			if (mousePos.x > pos.x && mousePos.x < pos.x + 80 &&
				mousePos.y > pos.y && mousePos.y < pos.y + 112 * 1.1f)
			{
				//std::cout << "\nMouse over button!  in ismouseover function \n\n" << endl;
				levels::setx(224 + j * 80);
				levels::sety(96 + i * 112);
				
				
				if (boxcheck[i][j] == true)
				{
					cout << "\nBox is already filled\n\n";
					return false;
				}
				else
				{
					boxcheck[i][j] = true;
					cout << "\nnow places is available\n\n";
					return true;
				}
			}
		}
	}
	cout << "\n\nMouse is not over button\n\n";
	return false;
}

void levels::setx(int x) {
	this->x = x;
}
void levels::sety(int y) {
	this->y = y;
}


////////////////////////

bool levels::checklevel()
{
	
	if (zomDiecheck == ZombieCount)
	{
		return true;

	}
	else
	{
		return false;
	}

}

void levels::setzombiecount(int count)
{
	ZombieCount = count;
}

void levels::setplantcount(int count)
{
	PlantCount = count;
}