#include<iostream>
#include <SFML/Graphics.hpp>
#include"../Project1/Plant.h"
using namespace sf;
using namespace std;
void plant::setvalues(int price, int health, int damage, bool isAlive, bool isAttacking, bool zombieInRange, int x, int y) {
	this->price = price;
	this->health = health;
	this->damage = damage;
	this->isAlive = isAlive;
	this->isAttacking = isAttacking;
	this->zombieInRange = zombieInRange;
	this->x = x;
	this->y = y;
	
}


plant::plant() {
	price = 0;
	health = 0;
	damage = 0;
	isAlive = false;
	isAttacking = false;
	zombieInRange = false;
	bulltmove = false;
	bulletcheck = false;
}
 plant::plant(int price, int health, int damage) {
	this->price = price;
	this->health = health;
	this->damage = damage;
	isAlive = false;
	isAttacking = false;
	zombieInRange = false;
}
 int plant::getPrice() {
	 return price;
 }
 int plant::getHealth() {
	 return health;
 }
 int plant::getDamage() {
	 return damage;
 }
 bool plant::getIsAlive() {
	 return isAlive;
 }
 bool plant::getIsAttacking() {
	 return isAttacking;
 }
 bool plant::getZombieInRange() {
	 return zombieInRange;
 }
 void plant::drawPlant(RenderWindow& window, int x, int y) {
	
	 plantSprite.setPosition(x, y);
	 
	 if(isAlive)
	 window.draw(plantSprite);
 
	// cout << "plant is done\n";
 }

 void plant::sethealth(int health) {
	 this->health = health;
 }
 void plant::setdamage(int damage) {
	 this->damage = damage;
 }
 void plant::setIsAlive(bool isAlive) {
	 this->isAlive = isAlive;
 }
 void plant::setisAttacking(bool isAttacking) {
	 this->isAttacking = isAttacking;
 }
 void plant::setzombieInRange(bool zombieInRange) {
	 
	 this->zombieInRange = zombieInRange;
 }
 void plant::setprice(int price) {
	 this->price = price;
 }
 //////////////////////////////'peashooter'////////////////////////
 void Peashooter::attack(RenderWindow& window	) {
	//cout << "Bullet before attack : " << bullet.bulletgetexists() << "\n";
	 if (zombieInRange == true)
	 {
		 if (bullet.bulletgetexists() == false)
		 {
			 if ((bullet::clock.getElapsedTime().asSeconds() > 3))
			 {
				 bullet.setx(plant::x + 80);
				 bullet.sety(plant::y + 10);
				 bulletcheck = true;
				 bullet::clock.restart();
				 bullet.bulletsetexists(true);
				 //cout << "I am in clockkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n";
			 }
		 }


		 if (bullet.bulletgetexists())
		 {
			// cout << "Bullet in main function           " << bullet.bulletgetexists() << endl;

			 bullet.moveBullet();
			 bullet.drawBullet(window);
			 // cout << "Drawing bullet" << endl; 
		 }
	 }
	 else {
		// cout << "not attacking" << endl;
	 }
 }


  Peashooter::Peashooter() {
	  cout << "Peas;";
	  doDamage = 25;
	  price = 100;
	  health = 100;
	  plantTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plantfff.png");
	  plantSprite.setTexture(plantTexture);
	  plantSprite.setScale(0.13f, 0.13f);
	 
	//plantSprite.setTextureRect(sf::IntRect(0, 0, 100, 100));

		
  }
  void Peashooter::setAttack() {
	
	  bullet.setx(plant::x);
	  bullet.sety(plant::y);
	  bullet.setcheck(true);
	//  cout << "bullet created" << endl;
	 
  }
  ////void Peashooter::zombieposition(int x, int y) {
	 // zombieY = this->y;
	 // zombieX = 790;

  //}

  FloatRect Peashooter::getGlobalBoundsforBullet() const {
	  return plantSprite.getGlobalBounds();
  }
  
  
  

 




  ///////////////////// sunflower/////////

  Sunflower::Sunflower() {
	 // cout << "Sunflower  ";
	  bool check = false;
	  Sun::x = plant::x;
	  Sun::y = plant::y;
	  price = 50;
	  health = 50;
	 plantTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\clipart225091.png");
	  plantSprite.setTexture(plantTexture);
	  plantSprite.setScale(0.11f, 0.11f);
  }



  void Sunflower::moveSunForFlower(RenderWindow& window)
  {
	  if (sunclcock.getElapsedTime().asSeconds() > 6)
	  {
		  Sun::y += 16;
		  drawSun(window);
		  sunclcock.restart();
	  }

  }
 //////////////////////////
  SnowPea::SnowPea() {
	 //// cout << "SnowPea  ";
	  doDamage = 25;
	  price = 150;
	  health = 150;
	  plantTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\pngwing.com (2).png");
	  plantSprite.setTexture(plantTexture);
	  plantSprite.setScale(0.09f, 0.09f);
  }
  void SnowPea::setAttack() {
	  bullet.setx(plant::x);
	  bullet.sety(plant::y);
	  bullet.setcheck(true);
	 // cout << "bullet created" << endl;
  }
  FloatRect SnowPea::getGlobalBoundsforBullet() const {
	  return plantSprite.getGlobalBounds();
  }

  void SnowPea::attack(RenderWindow& window) {
	  if (zombieInRange == true)
	  {
		  if (bullet.bulletgetexists() == false)
		  {
			  if ((bullet.clock.getElapsedTime().asSeconds() > 3))
			  {
				  bullet.setx(plant::x + 80);
				  bullet.sety(plant::y + 10);
				  bulletcheck = true;
				  bullet.clock.restart();
				  bullet.bulletsetexists(true);
				 // cout << "I am in clock\n";
			  }
		  }
	 
	  
		  if (bullet.bulletgetexists())
		  {
			  bullet.moveBullet();
			  bullet.drawBullet(window);
		  }
	  else {
		//  cout << "not attacking" << endl;
	  }
	  
	  }
  }

  ///////////////////////////
  Wallnut::Wallnut() {
	 // cout << "Wallnut  ";
	  price = 50;
	  health = 200;
	  plantTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\walnut.png");
	  plantSprite.setTexture(plantTexture);
	  plantSprite.setScale(0.4f, 0.5f);
	  move = false;
	  isAttacking = false;
  }
  ///////////////////////////////////
  CherryBomb::CherryBomb() {
	//  cout << "CherryBomb  ";
	  price = 150;
	  health = 150;
	  plantTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\clipart247868.png");
	  plantSprite.setTexture(plantTexture);
	  plantSprite.setScale(0.13f, 0.13f);
  }
  void CherryBomb::setAttack(bool hello) {
	  attack = hello;
  
  }


  ///////////////////////
  Repeater::Repeater() {
	 // cout << "Repeater  ";
	  doDamage = 50;
	  price = 200;
	  health = 200;
	  plantTexture.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\plants vs zombies pictures\\repeater.png");
	  plantSprite.setTexture(plantTexture);
	  plantSprite.setScale(0.09f, 0.09f);
  }

  void Repeater::attack(RenderWindow& window) {
	  if (zombieInRange == true)
	  {
		  if (bullet[0].bulletgetexists() == false)
		  {
			  if ((bullet[0].clock.getElapsedTime().asSeconds() > 2))
			  {
				  bullet[0].setx(plant::x + 100);
				  bullet[0].sety(plant::y + 10);
				  bulletcheckrepeater[0] = true;	
				  bullet[0].clock.restart();
				  bullet[0].bulletsetexists(true);
				  //cout << "I am in clock\n";
			  }
		  }
		  if (bullet[1].bulletgetexists() == false)
		  {
			  if ((bullet[1].clock.getElapsedTime().asSeconds() > 2))
			  {
				  bullet[1].setx(plant::x+50 );
				  bullet[1].sety(plant::y + 10);
				  bulletcheckrepeater[1] = true;
				  bullet[1].clock.restart();
				  bullet[1].bulletsetexists(true);
				//  cout << "I am in clock\n";
			  }
		  }
	  
		  if (bullet[0].bulletgetexists())
		  {
			  bullet[0].moveBullet();
			  bullet[0].drawBullet(window);
		  }
		  if (bullet[1].bulletgetexists())
		  {
			  bullet[1].moveBullet();
			  bullet[1].drawBullet(window);
		  }

	  
	  
	  }
  }

  void Repeater::setAttack() {
	  bullet[0].setx(plant::x+100);
	  bullet[0].sety(plant::y);
	  bullet[0].setcheck(true);
	  bullet[1].setx(plant::x);
	  bullet[1].sety(plant::y);
	  bullet[1].setcheck(true);
	 // cout << "bullet created" << endl;
  }
  