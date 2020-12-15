#include<stdio.h>
#include<vector>
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<time.h>
#include<vector>
#include<stdlib.h>
#include<sstream>
#include "entity.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickup.h"
#include "wall.h"
#include "menu.h"


using namespace std;

int main()
{
startgame :

	int i = 0;
	//counter 
	int counter = 0;
	int counter2 = 0;

	// random seed time for startX and starty
	int randomTime = 0;
	int r = 0; 
	srand(time(NULL));
	r = ( rand() % 100 )+ 1 ;

	// clock 
	sf::Clock clock; 
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clock4;
	sf::Clock clock5;
	sf::Clock clock6;
	sf::Clock clock7;
	sf::Clock clock8;
	sf::Clock clock9;

	// create window 
	sf::RenderWindow window(sf::VideoMode(1080 , 720), "LegendAdventure",sf::Style::Close);
	window.setFramerateLimit(120);

	//View 
	sf::View view1;
	view1.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
	view1.setCenter(sf::Vector2f(view1.getSize().x / 2, view1.getSize().y / 2));
	

	//create menu before game start 
	menu menu(window.getSize().x, window.getSize().y)	;

	// font game 
	sf::Font font; 
	font.loadFromFile("font.ttf");

	// menu text and font 
	sf::Text text; 
	text.setFont(font);
	text.setPosition(750, 0);
	text.setCharacterSize(15);

	// create game icon 
	sf::Image icon; 
	icon.loadFromFile("game icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y,icon.getPixelsPtr());

	//bgmmenu music
	sf::Music bgmInmenu;
	bgmInmenu.openFromFile("music1.ogg");
	bgmInmenu.setVolume(10);
	bgmInmenu.play();
	bgmInmenu.setLoop(true);

	//sound effect 
	sf::SoundBuffer bufferShoot;
	bufferShoot.loadFromFile("shooting5.wav");
	sf::Sound soundShoot;
	soundShoot.setBuffer(bufferShoot);
	soundShoot.setVolume(15);

	sf::SoundBuffer bufferHitted;
	bufferHitted.loadFromFile("hitted sound1.wav");
	sf::Sound soundHitted;
	soundHitted.setBuffer(bufferHitted);
	soundHitted.setVolume(15);

	sf::SoundBuffer bufferGotitem;
	bufferGotitem.loadFromFile("got item.wav");
	sf::Sound soundGotitem;
	soundGotitem.setBuffer(bufferGotitem);
	soundGotitem.setVolume(15);

	sf::SoundBuffer bufferMoney;
	bufferMoney.loadFromFile("got money.ogg");
	sf::Sound soundMoney;
	soundMoney.setBuffer(bufferMoney);
	soundMoney.setVolume(15);

	sf::SoundBuffer bufferBuy;
	bufferBuy.loadFromFile("buying item.ogg");
	sf::Sound soundBuy;
	soundBuy.setBuffer(bufferBuy);
	soundBuy.setVolume(15);

	sf::SoundBuffer bufferUlti;
	bufferUlti.loadFromFile("ulti sound1.wav");
	sf::Sound soundUlti;
	soundUlti.setBuffer(bufferUlti);
	soundUlti.setVolume(15);

	//bgmIngame music
	sf::Music bgmIngame;
	bgmIngame.openFromFile("bgmIngame.ogg");
	bgmIngame.setVolume(10);	

	// Player texture
	sf::Texture texture1 ;
	texture1.loadFromFile("knight 2.png");
	
	//coin texture 
	sf::Texture coin; 
	coin.loadFromFile("goldCoin1.png");

	//glove textre 
	sf::Texture glove;
	glove.loadFromFile("gloveofshoot.png");
	
	//ulti texture 
	sf::Texture ulti;
	ulti.loadFromFile("ulti.png");

	// boot texture 
	sf::Texture boot; 
	boot.loadFromFile("boot.png");
	
	// Potion texture
	sf::Texture potion;
	potion.loadFromFile("potion1.png");

	// ATCK up textuture 
	sf::Texture atkup;
	atkup.loadFromFile("atkup.png");

	// projectile texture
	sf::Texture redfireball; 
	redfireball.loadFromFile("red fire ball2.png");

	// class player and create
	class player Player1; 
	Player1.sprite.setTexture(texture1);

	//coffin texture 
	sf::Texture heart;
	heart.loadFromFile("heart.png");

	// Player projectile array 
	vector<projectile>::const_iterator iter; 
	vector<projectile> projectileArray ;

	// Player class projectile  and crate
	class projectile projectile1; 
	projectile1.sprite.setTexture(redfireball);

	// Eneny texture
	sf::Texture texturePurplebat;
	texturePurplebat.loadFromFile("purple bat.png");

	// Enemy array 
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;

	//Enemy class purple bat
	class enemy enemy1;
	enemy1.sprite.setTexture(texturePurplebat);
	enemy1.rect.setSize(sf::Vector2f(48, 70));
	enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 48, 70));
	enemyArray.push_back(enemy1);

	// Enemy texture 
	sf::Texture textureGhost;
	textureGhost.loadFromFile("Ghost.png");

	// wall array 
	vector<wall>::const_iterator iter16;
	vector<wall> wallArray;

	// wall class 
	class wall wall1;
	wall1.sprite.setTexture(texturePurplebat);
	int blockSize = 80;
	wall1.rect.setSize(sf::Vector2f(blockSize, blockSize));
	
	//building room with door 

	int roomSize = generateRandom(4)+4 ;
	int horizontaldoorup = 0; 
	int horizontaldoordown = 0; 
	int verticaldoorright = 0 ;
	int verticaldoorleft = 0;
	int startX = 0; 
	int startY = 0; 
	int rememberWidth = roomSize + r;
	int pastroomSize = 0;
	int pastdoor = 0;
	wall1.destructable = false ;

	// create randomsize and position of room 1

	 roomSize =  5 ;
	 horizontaldoorup = 3;
	 horizontaldoordown = 3;
	 verticaldoorright = 3;
	 verticaldoorleft = 3;
	 startX = 0;
	 startY = 0;
	 rememberWidth = roomSize + r;
	 pastroomSize = roomSize;
	 pastdoor = horizontaldoorup;
	 wall1.destructable = false;

		counter = 0; //up
		while (counter < roomSize+1)
		{	
				wall1.rect.setPosition((blockSize * counter) + startX, startY);
				wallArray.push_back(wall1);		
				counter++;
		}
		counter = 0;
		while (counter < roomSize + 1) //down
		{
			
				wall1.rect.setPosition((blockSize * counter) + startX, (blockSize * roomSize) + startY);
				wallArray.push_back(wall1);
				
			
			counter++;
		}
		counter = 0;
		
		while (counter < roomSize + 1)	//left
		{
			
				wall1.rect.setPosition(startX, (blockSize * counter) + startY);
				wallArray.push_back(wall1);
				
			
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//right
		{
			if (counter != verticaldoorright)
			{
				wall1.rect.setPosition((blockSize * roomSize) + startX, (blockSize * counter) + startY);
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;

		// create room 2 randomside				1 --> x 


		startX = (blockSize * 5) ;
		startY = (blockSize * 6) ;
		roomSize =  7 ;
		horizontaldoorup = 4;
		horizontaldoordown = 4;
		verticaldoorright = 4;
		verticaldoorleft = 4;
		wall1.destructable = false; 

		while (counter < roomSize + 1)//up
		{
			
				wall1.rect.setPosition((blockSize * counter) + startX, 0 );
				wallArray.push_back(wall1);
				counter++;
		}
		counter = 0;

		while (counter < roomSize + 1) //down
		{
			if (counter != horizontaldoordown)
			{
				wall1.rect.setPosition((blockSize * counter) + startX, (blockSize * roomSize) + startY);
				wallArray.push_back(wall1);

			}
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//left
		{
		
				wall1.rect.setPosition(startX, (blockSize * counter) + startY);
				wallArray.push_back(wall1);

			
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//right 1 
		{
			if (counter != verticaldoorright)
			{
				wall1.rect.setPosition((blockSize * roomSize) + startX, (blockSize * counter) + startY);
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;

		while (counter < roomSize )	//right upper 2 
		{
			
				wall1.rect.setPosition((blockSize * roomSize) + startX, (blockSize * counter) );
				wallArray.push_back(wall1);
				counter++; 
		}
		counter = 0;

		//create things in room 2
		counter = 0;

		while (counter < (roomSize - 1 ))
		{
			counter2 = 0;
			while (counter2 <  2 * (roomSize - 1 ))
			{
				int tempRandom = generateRandom(5);

				if (tempRandom == 1 )
				{
					//create random box 
					wall1.destructable = true;
					wall1.rect.setPosition((counter * blockSize ) + startX + blockSize, (counter2 * blockSize) + blockSize);
					wall1.rect.setFillColor(sf::Color::Green);
					wallArray.push_back(wall1);
				}
				if (tempRandom == 2)
				{
					//create enemy
					enemy1.rect.setPosition((counter* blockSize) + startX + blockSize, (counter2* blockSize)  + blockSize);
					enemyArray.push_back(enemy1);
				}

				counter2++;
			}
			counter++; 
		}
		counter = 0;
		counter2 = 0; 
		wall1.rect.setFillColor(sf::Color::Black);



		// room 3 
		

		startX = (blockSize * 12);
		startY = (blockSize * 8 );
		roomSize = 6 ;
		horizontaldoorup = 2;
		horizontaldoordown = 2;
		verticaldoorright = 2;
		verticaldoorleft = 2;
		wall1.destructable = false;


		while (counter < roomSize + 1)//up
		{

			wall1.rect.setPosition((blockSize * counter) + startX, startY );
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;
		while (counter < roomSize + 1)//down
		{

			wall1.rect.setPosition((blockSize * counter) + startX, startY + (4 * blockSize));
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;
		while (counter < roomSize - 2 )	//right 1 
		{
			if (counter != verticaldoorright)
			{
				wall1.rect.setPosition((blockSize * roomSize) + startX, startY + (counter * blockSize));
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;

		// room 4 


		startX = (blockSize * 18);
		startY = (blockSize * 4);
		roomSize = 12 ;
		horizontaldoorup = 6;
		horizontaldoordown = 6;
		verticaldoorright = 6;
		verticaldoorleft = 6;
		wall1.destructable = false;


		while (counter < roomSize + 1)//up
		{

			wall1.rect.setPosition((blockSize * counter) + startX, startY);
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;
		
		while (counter < roomSize + 1)//down
		{

			wall1.rect.setPosition((blockSize * counter) + startX, startY + (blockSize * roomSize) );
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//left
		{

			if (counter != verticaldoorleft)
			{
			
			wall1.rect.setPosition(startX, (blockSize * counter) + startY);
			wallArray.push_back(wall1);
			}

			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//right 
		{

				wall1.rect.setPosition(startX + (blockSize * roomSize), (blockSize * counter) + startY);
				wallArray.push_back(wall1);

			counter++;
		}

		counter = 0;
		// room 5 

		startX = (blockSize * 7 ) ;
		startY = (blockSize * 14 )	;
		roomSize = 3 ;
		horizontaldoorup = 1;
		horizontaldoordown = 1;
		verticaldoorright = 1;
		verticaldoorleft = 1;
		wall1.destructable = false;

		while (counter < roomSize + 1)	//left
		{
				wall1.rect.setPosition(startX, (blockSize * counter) + startY);
				wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//Right
		{
			wall1.rect.setPosition(startX + (blockSize * (roomSize + 1 )), (blockSize * counter) + startY);
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)//down
		{
			if (counter != horizontaldoordown)
			{
				wall1.rect.setPosition((blockSize * counter) + startX, startY + (blockSize * roomSize));
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;

		// room 6 //secret room need key

		startX = (blockSize * 4 );
		startY = (blockSize * 17);
		roomSize = 6 ;
		horizontaldoorup = 4 ;
		horizontaldoordown = 0;
		verticaldoorright = 0;
		verticaldoorleft = 0;
		wall1.destructable = false;

		while (counter < roomSize + 1)	//left
		{
			wall1.rect.setPosition(startX, (blockSize * counter) + startY);
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)	//Right
		{
			wall1.rect.setPosition(startX + (blockSize * (roomSize + 1)), (blockSize * counter) + startY);
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)//down
		{
			if (counter != horizontaldoordown)
			{
				wall1.rect.setPosition((blockSize * counter) + startX, startY + (blockSize * roomSize));
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;
		while (counter < roomSize + 1)//up
		{
			if (counter != horizontaldoorup)
			{
				wall1.rect.setPosition((blockSize * counter) + startX, startY);
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;




	/*checksize ----------------------------------------
	printf("%d\n", textureGhost.getSize().x);
	printf("%d\n", textureGhost.getSize().y);
	---------------------------------------------------*/



	// text array 
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textdisplayArray;

	// class text and crate
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);
	
	// text array 
	vector<pickup>::const_iterator iter12;
	vector<pickup> pickupArray;

	// pickup coin class 
	class pickup pickup1;
	pickup1.sprite.setTexture(coin);

	pickupArray.push_back(pickup1);
	pickup1.isCoin = true;


	//
	

	while (window.isOpen())
	{
	
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		
			switch ( event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveup();
					menu.atText = 0; 
					break;

				case sf::Keyboard::Down:
					menu.movedown();
					menu.atText = 1; 
					break;
				}
			}
			
		}
		
		window.clear(sf::Color(150,150,150));
		
		// draw menu 

		if (menu.enterplay == false)
		{
			menu.draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && menu.atText == 0 )
			{
				bgmInmenu.stop();
				bgmIngame.play();
				bgmIngame.setLoop(true);
				menu.enterplay = true; 
				Player1.Arrive = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && menu.atText == 1)
			{
				window.close();
			}
		}


		else
		{

			// time 
			sf::Time elapsed1 = clock.getElapsedTime();
			sf::Time elapsed2 = clock2.getElapsedTime();
			sf::Time elapsed3 = clock3.getElapsedTime();
			sf::Time elapsed4 = clock4.getElapsedTime();
			sf::Time elapsed5 = clock5.getElapsedTime();
			sf::Time elapsed6 = clock6.getElapsedTime();
			sf::Time elapsed7 = clock7.getElapsedTime();
			sf::Time elapsed8 = clock8.getElapsedTime();
			sf::Time elapsed9 = clock9.getElapsedTime();

			// delay playeranimation walk 
			if (elapsed3.asSeconds() >= 0.05)
			{
				clock3.restart();
				Player1.counterwalk++;
					if (Player1.counterwalk >= 3)
					{
						Player1.counterwalk = 0;
					}				
			}

			counter = 0;

			// delay enemy animation walk 
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (elapsed3.asSeconds() >= 0.05)
				{
					clock3.restart();
					enemyArray[counter].counterwalk++;
					if (enemyArray[counter].counterwalk >= 3)
					{
						enemyArray[counter].counterwalk = 0;
					}
				}
				counter++;
			}
			counter = 0;

			//delay animation for projectile 
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (elapsed4.asSeconds() >= 0.5)
				{
					clock4.restart();
					projectileArray[counter].counter++;
					if (projectileArray[counter].counter >= 4)
					{
						projectileArray[counter].counter = 0;
					}
				}
				counter++;
			}

			counter = 0;
			//enemy colied with wall 
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				counter2 = 0;
				for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
				{
					if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
					{
						if (enemyArray[counter].direction == 1) // left 
						{
							enemyArray[counter].enemycanmoveleft = false;
							enemyArray[counter].rect.move(3, 0);
						}
						else if (enemyArray[counter].direction == 2) // right
						{
							enemyArray[counter].enemycanmoveright = false;
							enemyArray[counter].rect.move(-3, 0);
						}
						else if (enemyArray[counter].direction == 3) // up
						{
							enemyArray[counter].enemycanmoveup = false;
							enemyArray[counter].rect.move(0, 3);
						}
						else if (enemyArray[counter].direction == 4) // down
						{
							enemyArray[counter].enemycanmovedown = false;
							enemyArray[counter].rect.move(0, -3);
						}
					}
					else
					{

					}
					counter2++;
				}
				counter++;
			}



			counter = 0;
			counter2 = 0;

			//player colied with wall
			for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
			{
				if (Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
				{
					if (Player1.direction == 1) // left 
					{
						Player1.playercanmoveleft = false;
						Player1.rect.move(Player1.push, 0);

					}
					else if (Player1.direction == 2) // right
					{
						Player1.playercanmoveright = false;
						Player1.rect.move(-Player1.push, 0);
					}
					else if (Player1.direction == 3) // up
					{
						Player1.playercanmoveup = false;
						Player1.rect.move(0, Player1.push);
					}
					else if (Player1.direction == 4) // down
					{
						Player1.playercanmovedown = false;
						Player1.rect.move(0, -Player1.push);
					}
				}
				else
				{

				}
				counter++;
			}
			counter = 0;

			// projectile colied with box 
			counter = 0;
			if (elapsed5.asSeconds() >= 0.1)
			{
				clock5.restart();
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					counter2 = 0;
					for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
					{
						if (projectileArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
						{
							soundHitted.play();
							if (wallArray[counter2].destructable == true)
							{
								wallArray[counter2].hp -= 1;
								if (wallArray[counter2].hp <= 0)
								{
									wallArray[counter2].destroy = true;
								}
							}
							projectileArray[counter].hit = true;
						}
						counter2++;
					}
					counter++;
				}
				counter = 0;
			}

			if (Player1.Arrive == true)
			{
			// enemy colied with player (player take damage)  
				counter = 0;
				if (elapsed2.asSeconds() >= 1.5)
				{
					clock2.restart();
					for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
					{
						if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
						{

							textDisplay1.text.setFillColor(sf::Color::Red);
							textDisplay1.text.setString(to_string(enemyArray[counter].attackdamge));
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);

							Player1.hp -= enemyArray[counter].attackdamge;
							if (Player1.hp <= 0)
							{
								Player1.Arrive = false;
								Player1.hp = 0;
							}
						}
						counter++;
					}

				}
			}



			if (Player1.Arrive == true)
			{
			// item colied with player 
				counter = 0;
				for (iter12 = pickupArray.begin(); iter12 != pickupArray.end(); iter12++)
				{
					if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
					{
						if (pickupArray[counter].isCoin == true && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
						{
							soundMoney.play();

							pickup1.isAtkyp = false;
							pickup1.isBoot = false;
							pickup1.isCoin = true; 
							pickup1.isGlove = false; 
							pickup1.isUlti = false;
							pickup1.isPotion = false; 
							pickup1.isHeart = false;

							textDisplay1.text.setFillColor(sf::Color::Yellow);
							textDisplay1.text.setString(to_string(pickupArray[counter].coinvalue));
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);

							Player1.playermoney += pickup1.coinvalue;

						}
			

						else if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == true && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
						{
							soundGotitem.play();
							pickup1.isAtkyp = false;
							pickup1.isBoot = false;
							pickup1.isGlove = true;
							pickup1.isCoin = false;
							pickup1.isUlti = false;
							pickup1.isPotion = false;
							pickup1.isHeart = false;
							textDisplay1.text.setFillColor(sf::Color::Yellow);
							textDisplay1.text.setString("Glove");
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);
							Player1.playerglove = true ; 
							projectile1.fastDelay -= 0.5 ;
					
						}
							
						
						else if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == true && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
						{
							soundGotitem.play();
							projectile1.shootlimit = 9;
							pickup1.isAtkyp = false;
							pickup1.isBoot = false;
							pickup1.isCoin = false;
							pickup1.isGlove = false;
							pickup1.isUlti = true;
							pickup1.isPotion = false;
							pickup1.isHeart = false;
							textDisplay1.text.setFillColor(sf::Color::Yellow);
							textDisplay1.text.setString("Ulti");
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);
							Player1.playerulti = true;
						}

						else if ( pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == true  && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
						{
							soundGotitem.play();

							pickup1.isAtkyp = true;
							pickup1.isBoot = false;
							pickup1.isCoin = false;
							pickup1.isGlove = false;
							pickup1.isUlti = false;
							pickup1.isPotion = false;
							pickup1.isHeart = false;
							textDisplay1.text.setFillColor(sf::Color::Yellow);
							textDisplay1.text.setString("+1 AttackDamage");
							projectile1.attackdamge += pickup1.atkup; 
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);
						}

						else if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == true && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
						{
							soundGotitem.play();
						
							pickup1.isAtkyp = false;
							pickup1.isBoot = true;
							pickup1.isCoin = false;
							pickup1.isGlove = false;
							pickup1.isUlti = false;
							pickup1.isPotion = false;
							pickup1.isHeart = false;
							textDisplay1.text.setFillColor(sf::Color::Yellow);
							textDisplay1.text.setString("+0.25 speed");
							Player1.movementSpeed += pickup1.bootspeed;
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);
						}

						else if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == true && pickupArray[counter].isHeart == false)
						{
							soundGotitem.play();
		
							pickup1.isAtkyp = false;
							pickup1.isBoot = false;
							pickup1.isCoin = false;
							pickup1.isGlove = false;
							pickup1.isUlti = false;
							pickup1.isPotion = true;
							pickup1.isHeart = false;
							textDisplay1.text.setFillColor(sf::Color::Green);
							textDisplay1.text.setString("+10 HP");
							Player1.hp += pickup1.heal;
							if (Player1.hp >= Player1.maxHp)
							{
								Player1.hp = Player1.maxHp; 
							}
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);
							Player1.playerulti = true;
						}

						else if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == true)
						{
						soundGotitem.play();

						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.isHeart = true; 
						textDisplay1.text.setFillColor(sf::Color::Red);
						textDisplay1.text.setString("+10 MAX HP");
						Player1.maxHp += Player1.maxHp;

						if (Player1.hp >= Player1.maxHp)
						{
							Player1.hp = Player1.maxHp;
						}
						textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
						textdisplayArray.push_back(textDisplay1);
						Player1.playerulti = true;
						}

						pickupArray[counter].picked = true;
				
					}
					counter++;
				}

				counter = 0;
			}

			// shooting hitted projectile 
			if (Player1.Arrive == true)
			{
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					counter2 = 0;
					for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
					{
						if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
						{
							soundHitted.play();
							// text show damge hitted  
							textDisplay1.text.setFillColor(sf::Color::Red);
							textDisplay1.text.setString(to_string(projectileArray[counter].attackdamge));
							textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + (enemyArray[counter2].rect.getSize().x) * 2 / 5, enemyArray[counter2].rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);

							//damge to enemy 
							enemyArray[counter2].hp -= projectileArray[counter].attackdamge;
							projectileArray[counter].hit = true;

							//enemy die 
							if (enemyArray[counter2].hp <= 0)
							{
								enemyArray[counter2].arrive = false;
							}
						}





						counter2++;
					}
					counter++;
				}
			}
			// delete projectile 
			counter = 0;
			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				if (projectileArray[counter].hit == true)
				{
					projectileArray.erase(iter);
					break;
				}
				counter++;
			}
			counter = 0;

			//delete dead enemy 
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (enemyArray[counter].arrive == false)
				{
					if (generateRandom0(enemyArray[counter].percentDropCoin) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = true;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(coin);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					else if (generateRandom0(enemyArray[counter].percentDropGlove) == 1)
					{
						
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = true;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(glove);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}
					else if (generateRandom0(enemyArray[counter].percentDropUlti) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = true;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(ulti);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}
					else if (generateRandom0(enemyArray[counter].percentDropBoot) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = true;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(boot);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}
					else if (generateRandom0(enemyArray[counter].percentDropPotion) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = true;
						pickup1.sprite.setTexture(potion);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}
					else if (generateRandom0(enemyArray[counter].percentDropAtkup) == 1)
					{
						pickup1.isAtkyp = true;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(atkup);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}




					enemyArray.erase(iter4);
					break;
				}
				counter++;

			}
			counter = 0;

			// delete textdisplay
			counter = 0;
			for (iter8 = textdisplayArray.begin(); iter8 != textdisplayArray.end(); iter8++)
			{
				if (textdisplayArray[counter].destroy == true)
				{
					textdisplayArray.erase(iter8);
					break;
				}
				counter++;
			}
			counter = 0;

			//delete detroyed wall 

			counter = 0;

			for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
			{
				if (wallArray[counter].destroy == true)
				{
					//drop coin 
					if (generateRandom0(wallArray[counter].percentDropCoin) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = true;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(coin);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					else if (generateRandom0(wallArray[counter].percentDropGlove) == 1)
					{

						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = true;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(glove);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					else if (generateRandom0(wallArray[counter].percentDropUlti) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = true;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(ulti);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					else if (generateRandom0(wallArray[counter].percentDropBoot) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = true;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(boot);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					else if (generateRandom0(wallArray[counter].percentDropPotion) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = true;
						pickup1.sprite.setTexture(potion);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					else if (generateRandom0(wallArray[counter].percentDropAtkup) == 1)
					{
						pickup1.isAtkyp = true;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.sprite.setTexture(atkup);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}

					wallArray.erase(iter16);
					break;
				}
				counter++;
			}
			counter = 0;

			// delete picked item
			counter = 0;
			for (iter12 = pickupArray.begin(); iter12 != pickupArray.end(); iter12++)
			{
				if (pickupArray[counter].picked == true)
				{
					pickupArray.erase(iter12);
					break;
				}
		
				counter++;
			}
			counter = 0;

			//create more enemy 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				enemy1.rect.setPosition(generateRandom(1080), generateRandom(720));
				enemyArray.push_back(enemy1);
			}

			//create more money 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			{
					pickup1.rect.setPosition(generateRandom(1080), generateRandom(720));
					pickupArray.push_back(pickup1);	
			}

			if (Player1.Arrive == true)
			{		
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						 
						if (elapsed1.asSeconds() >= projectile1.shootingspeed)
						{
							clock.restart();
							soundShoot.play();
						// set up projectile 
							if (Player1.playerglove == false )
							{

								projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2, Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2);
								projectile1.direction = Player1.direction;
								projectileArray.push_back(projectile1);
								Player1.playerglove = false;

							}

							if (Player1.playerglove == true)
							{

								projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2, Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2);
								projectile1.direction = Player1.direction;
								projectileArray.push_back(projectile1);


								if (elapsed6.asSeconds() >= projectile1.fastDelay)
								{

									clock6.restart();
									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + 25, Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + 25);
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2, Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2);
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 - 25, Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 - 25);
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);
								}

							}
						
							if (Player1.playerulti == true && sf::Keyboard::isKeyPressed(sf::Keyboard::B))
							{
								soundUlti.play();
									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(30), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(30));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(30), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(30));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(30), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(30));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);


									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(40), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(40));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(40), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(40));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(40), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(40));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);


									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(50), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(50));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(50), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(50));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);

									projectile1.rect.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) / 2 - (projectile1.rect.getSize().x) / 2 + generateRandom(50), Player1.rect.getPosition().y + (Player1.rect.getSize().y) / 2 - (projectile1.rect.getSize().y) / 2 + generateRandom(50));
									projectile1.direction = Player1.direction;
									projectileArray.push_back(projectile1);


									clock6.restart();

									textDisplay1.text.setFillColor(sf::Color::White);
									if (projectile1.shootlimit >= 1)
									{
										textDisplay1.text.setString(to_string(projectileArray[counter].shootlimit));
										textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 2 / 5, Player1.rect.getPosition().y);
										textdisplayArray.push_back(textDisplay1);
										projectile1.shootlimit--;
									}
									else if (projectile1.shootlimit <= 0)
									{
										projectile1.shootlimit = 10;
										Player1.playerulti = false;
										textDisplay1.text.setString("OUT OF SPECIAL ATTACK");
										textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 2 / 5, Player1.rect.getPosition().y);
										textdisplayArray.push_back(textDisplay1);
										projectile1.shootlimit--;
									}
								






							}
							
					}		
					

				}
			

				counter = 0;

			}
			// draw projectile

			for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
			{
				projectileArray[counter].updateprojectileAnimation();
				projectileArray[counter].updateprojectile();
				//window.draw(projectileArray[counter].rect);
				window.draw(projectileArray[counter].sprite);
				counter++;
			}
			counter = 0;

			// draw item
			for (iter12 = pickupArray.begin(); iter12 != pickupArray.end(); iter12++)
			{
				//update pickup 
				pickupArray[counter].updatepickup();
				//window.draw(pickupArray[counter].rect);
				window.draw(pickupArray[counter].sprite);
				counter++;
			}
			counter = 0;

			for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
			{
				//update pickup 
				wallArray[counter].updatewall();
				//window.draw(pickupArray[counter].rect);
				window.draw(wallArray[counter].rect);
				counter++;
			}
			counter = 0;

			// draw text
			for (iter8 = textdisplayArray.begin(); iter8 != textdisplayArray.end(); iter8++)
			{
				//update textdisplay 
				textdisplayArray[counter].updateTextdisplay();
				window.draw(textdisplayArray[counter].text);
				counter++;
			}
			counter = 0;

			// draw enemy
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				enemyArray[counter].updateenemy();
				enemyArray[counter].updatemovementenemy();
				//window.draw(enemyArray[counter].rect);
				window.draw(enemyArray[counter].sprite);
				counter++;
			}
			counter = 0;

			// Player1 still Arrive 
			if (Player1.Arrive == true)
			{

			//update player
			Player1.update();

			//update movement 
			Player1.updatemovement();

			// draw player 
			//window.draw(Player1.rect);
			window.draw(Player1.sprite);


			//set player view
			window.setView(view1);
			view1.setCenter(Player1.rect.getPosition());

			//draw player hp
			text.setPosition(Player1.rect.getPosition().x + 300, Player1.rect.getPosition().y + 335);
			text.setFillColor(sf::Color(250, 20, 0));
			text.setString("Player HP : " + to_string(Player1.hp) );
			window.draw(text);
			text.setFillColor(sf::Color::White);

			//draw player max hp
			text.setPosition(Player1.rect.getPosition().x + 480, Player1.rect.getPosition().y + 335);
			text.setFillColor(sf::Color(175, 0, 0));
			text.setString(" \\ " + to_string(Player1.maxHp));
			window.draw(text);
			text.setFillColor(sf::Color::White);

			// draw player money 
			text.setPosition(Player1.rect.getPosition().x + 300, Player1.rect.getPosition().y - 335);
			text.setString("Player money : " + to_string(Player1.playermoney));
			window.draw(text);
	
			
			}
			//Player1 dead 
			else if (Player1.Arrive == false )
			{	
				window.clear();
				goto startgame;
				
			}

			else
			{
				//nothing
			}


			

			
			
		}

		// update window 
		window.display();

	}

	return 0;
} 

