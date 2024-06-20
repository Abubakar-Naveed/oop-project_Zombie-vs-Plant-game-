
#include <SFML/Graphics.hpp>
#include <ctime>
#include <fstream>
#include"MainGame.h"
#include"mainmenu.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;

int levelnum = 1;
struct coordinats {
	int x;
	int y;
};



//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	
	map_image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\new images\\night.png");
//C:\Users\Hp\Desktop\project\Project1\Project1
//map_image.loadFromFile("../SFML/Images/backwindow.jpg");

	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	s_map.setScale(1.0f, 1.158f);
	window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\grid.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 160);

	window.draw(s_map);
}


int main()
{
	mainGame game;
	mainmenu menu;
	instructions Instruction;
	highestscore score;
	Entername name;
	MenuButton pause;
	MenuButton SavegameButton;
	resume resum;

	

	bool savegamebool = false;
	int gamestatus = -1;
	int pauseremume = false;
	cout << "New file\n";
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("C:\\Users\\Hp\\Desktop\\project\\Project1\\Project1\\Images\\icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	////////////////////
	pause.setMenuButton(window, "Pause", 850, 0, 20);
	SavegameButton.setMenuButton(window, "Save Game", 1000, 0, 20);
	////////////////////

	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}






	game.drawgrid(window);


	Clock timeMoney;

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();
		clock.restart();
		time = time / 800;








		if (gamestatus == -1)
		{

			menu.loadmenu(window);
			menu.drawmenu(window);
			//cout << "Menu is drwan\n";
			Event event2;
			while (window.pollEvent(event2))
			{
				if (event2.type == Event::Closed)
					window.close();
				if (event2.type == sf::Event::MouseButtonPressed && event2.mouseButton.button == sf::Mouse::Left)
				{
					cout << "I am in state -1\n";
					gamestatus = menu.checkclick(window);
					cout << "game status " << gamestatus << endl;
					break;

				}
			}

		}
		if (gamestatus == 2)
		{
			Event event3;
			while (window.pollEvent(event3))
			{
				Instruction.loadinstructions(window);
				Instruction.drawinstructions(window);
				if (event3.type == Event::Closed)
					window.close();
				if (event3.type == sf::Event::MouseButtonPressed && event3.mouseButton.button == sf::Mouse::Left && gamestatus == 2)
				{
					cout << "I am in state 2\n";
					gamestatus = Instruction.checkclick(window);
					cout << "game status " << gamestatus << endl;
					break;
				}

			}
		}

		if (gamestatus == 4)
		{
			Event event4;
			while (window.pollEvent(event4))
			{
				score.loadscore(window);
				score.drawscore(window);
				if (event4.type == Event::Closed)
					window.close();
				if (event4.type == sf::Event::MouseButtonPressed && event4.mouseButton.button == sf::Mouse::Left && gamestatus == 4)
				{

					gamestatus = score.checkclick(window);
					break;
				}

			}
		}



		if (gamestatus == 5)
		{
			Event event5;
			while (window.pollEvent(event5))
			{
				resum.loadresume(window);
				resum.drawresume(window);
				if (event5.type == Event::Closed)
					window.close();
				if (event5.type == sf::Event::MouseButtonPressed && event5.mouseButton.button == sf::Mouse::Left && gamestatus == 5)
				{
					gamestatus = resum.checkclick(window);
					if (gamestatus == 1)
					{
						gamestatus = 3;
					}
					else if (gamestatus == 0)
					{
						pauseremume = false;
					}


					break;
				}

			}
		}


		if (gamestatus == 1)
		{
			game.readfromfile();
			gamestatus = 0;
		}


		if (gamestatus == 3)
		{
			window.close();
		}

		if (gamestatus == 0)
		{
			createBack(window);
			game.levelupdate(window);



			if (pauseremume == false)
			{

				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
					{
						if (pause.MouseInArea(window))
						{
							pauseremume = true;
							gamestatus = 5;
							break;
						}
						if (SavegameButton.MouseInArea(window))
						{
							savegamebool = true;
							break;
						}

						game.cardcheck(window);
						game.createplant(window);
						game.sunclick(window);

						/*if (game.getgameovermain())
						{
							cout << "Game is over in main buuton\n";
							gamestatus = -1;
						}*/
					}
				}
				if (savegamebool)
				{
					game.savegame(savegamebool);
					cout << "game is savedd\n";
				//	gamestatus = 3;
					savegamebool = false;
				}

				game.movegame(window, event);
				pause.Draw_button(window);
				SavegameButton.Draw_button(window);
				window.setSize(sf::Vector2u(1200, 760));


			}
		}

		window.display();
	}

	return 0;
}