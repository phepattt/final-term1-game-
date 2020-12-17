#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<time.h>
#include<vector>
#include<stdlib.h>
#include<sstream>
#include<utility>
#include<algorithm>
#include<string>
#include <SFML/Graphics.hpp>
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include "entity.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickup.h"
#include "wall.h"
#include "menu.h"
#include "destroy.h"

using namespace std;

int main()
{
startgame :
	int delayspawn = 0;
	int collecter1 = 0;
	int enemytype = 0;
	int spawntime = 8 ;
	int teleport = 0 ;
	int mod1 = 0;
	//counter 
	int counter = 0;
	int counter2 = 0;

	sf::Clock countdownclock; 
	sf::Time countdown = countdownclock.getElapsedTime();

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
	sf::Clock clock10;
	sf::Clock clock11;
	sf::Clock clock12;
	// create window 
	sf::RenderWindow window(sf::VideoMode(1080 , 720), "LegendAdventure",sf::Style::Close);
	window.setFramerateLimit(120);

	//View 
	sf::View view1;
	view1.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
	view1.setCenter(sf::Vector2f(view1.getSize().x / 2, view1.getSize().y / 2));

	//create menu before game start 
	menu menu(window.getSize().x, window.getSize().y)	      ;

	// font game 
	sf::Font font; 
	font.loadFromFile("font.ttf");

	// menu text and font 
	sf::Text text; 
	text.setFont(font);
	text.setPosition(750, 50);
	text.setCharacterSize(15);
	//
	sf::Text score;
	score.setCharacterSize(30);
	score.setFont(font);
	score.setPosition(750, 0);
	

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

	sf::SoundBuffer bufferFin;
	bufferFin.loadFromFile("finish boss.ogg");
	sf::Sound soundFin;
	soundFin.setBuffer(bufferFin);
	soundFin.setVolume(15);

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
	
	// floor layer 
	sf::Texture floor;
	floor.loadFromFile("floor5.jpg");

	//coin texture 
	sf::Texture coin; 
	coin.loadFromFile("goldCoin1.png");





	//glove textre 
	sf::Texture glove;
	glove.loadFromFile("gloveofshoot.png");
	
	// key teture 
	sf::Texture key;
	key.loadFromFile("key.png");

	//ulti texture 
	sf::Texture ulti;
	ulti.loadFromFile("ulti.png");

	// boot texture 
	sf::Texture boot; 
	boot.loadFromFile("boot.png");
	
	// slime texture 
	sf::Texture slime;
	slime.loadFromFile("blue silme.png");

	// zombiepigman texture 
	sf::Texture pigman;
	pigman.loadFromFile("zombie pigman.png");

	// Potion texture
	sf::Texture potion;
	potion.loadFromFile("potion1.png");

	//barrel texture 
	sf::Texture barrel;
	barrel.loadFromFile("barrel.png");

	//text boss 
	sf::Texture boss; 
	boss.loadFromFile("boss.png");

	// ATCK up textuture 
	sf::Texture atkup;
	atkup.loadFromFile("atkup.png");

	// projectile texture
	sf::Texture redfireball; 
	redfireball.loadFromFile("red fire ball2.png");

	// class player and create
	class player Player1; 
	Player1.sprite.setTexture(texture1);
	Player1.playerkey = false;

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
	int blockSize = 90;

	// wall class 
	class wall wall1;
	wall1.sprite.setTexture(floor);
	wall1.sprite.setTextureRect(sf::IntRect(180, 360, 90, 90));
	wall1.rect.setSize(sf::Vector2f(blockSize, blockSize));
	wallArray.push_back(wall1);


	// floor array 
	vector<wall>::const_iterator iter20;
	vector<wall> floorArray;

	// floor class 
	class wall floor1;
	floor1.sprite.setTexture(floor);
	floor1.sprite.setTextureRect(sf::IntRect(90 * 6, 90 * 8 , 90, 90));
	floorArray.push_back(floor1);

	// text array 
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textdisplayArray;

	// class text and crate
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);

	// pickup array 
	vector<pickup>::const_iterator iter12;
	vector<pickup> pickupArray;

	// pickup coin class 
	class pickup pickup1;	
	pickup1.isCoin = true;
	pickup1.sprite.setTexture(coin);

	// key array 
	vector<pickup>::const_iterator iter24;
	vector<pickup> keyArray;

	// pickup key class 
	class pickup key1;
	key1.isKey = true;

	key1.sprite.setTexture(key);
	key1.rect.setPosition( 23 * blockSize, 6 * blockSize);
	key1.isKey = true;
	keyArray.push_back(key1);


	// destroy array 
	vector<destroy>::const_iterator iter2;
	vector<destroy> destroyArray;

	//destroy class 
	class  destroy destroy1;


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

	 counter = 0;
	 while (counter < roomSize )
	 {
		 counter2 = 0;
		 while (counter2 < roomSize  )
		 { 
			 floor1.sprite.setPosition((blockSize * counter), (blockSize * counter2));
			 floorArray.push_back(floor1);
			 counter2++; 
		 }
		 counter++; 
	 }
	 counter = 0 ;
	 counter2 = 0;

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


		counter = 0;
		while (counter < roomSize)
		{
			counter2 = 0;
			while (counter2 < 2*roomSize)
			{
				floor1.sprite.setPosition((blockSize * counter)+ startX, (blockSize * counter2));
				floorArray.push_back(floor1);
				counter2++;
			}
			counter++;
		}
		counter = 0;
		counter2 = 0;


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
			while (counter2 <  2 * (roomSize - 2 ))
			{
				int tempRandom = generateRandom(20);

				if (tempRandom == 1 || tempRandom == 2 || tempRandom == 3 )
				{
					//create random box 
					wall1.destructable = true;
					wall1.sprite.setTexture(barrel);
					wall1.sprite.setTextureRect(sf::IntRect(0, 180, 90, 90));
					wall1.rect.setPosition((counter * blockSize ) + startX + blockSize, (counter2 * blockSize) + blockSize);
					wall1.rect.setFillColor(sf::Color::Green);
					wallArray.push_back(wall1);
					wall1.sprite.setTexture(floor);
					wall1.sprite.setTextureRect(sf::IntRect(180, 360, 90, 90));

				}
				else if (tempRandom == 5)
				{
					//create enemy
					enemy1.rect.setPosition((counter* blockSize) + startX + blockSize, (counter2* blockSize)  + blockSize);
					enemyArray.push_back(enemy1);
				}

				else if (tempRandom == 6)
				{
					//create enemy
					enemy1.sprite.setTexture(slime);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize);
					enemyArray.push_back(enemy1);
				}
				else if (tempRandom == 7)
				{
					//create enemy
					enemy1.sprite.setTexture(pigman);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize);
					enemyArray.push_back(enemy1);
				}
				else if (tempRandom == 8)
				{
					//create enemy
					enemy1.sprite.setTexture(textureGhost);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize);
					enemyArray.push_back(enemy1);
				}
			

				counter2++;
			}
			counter++; 
		}
		counter = 0;
		counter2 = 0; 



		// room 3 
		

		startX = (blockSize * 12);
		startY = (blockSize * 8 );
		roomSize = 6 ;
		horizontaldoorup = 2;
		horizontaldoordown = 2;
		verticaldoorright = 2;
		verticaldoorleft = 2;
		wall1.destructable = false;

		counter = 0;
		while (counter < roomSize + 1)
		{
			counter2 = 0;
			while (counter2 < roomSize - 2)
			{
				if (counter2 != 3 && counter2 != 1)
				{
					
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
				}

				else
				{
					floor1.sprite.setTextureRect(sf::IntRect(90 * 7, 90 * 8, 90, 90));
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
					floor1.sprite.setTextureRect(sf::IntRect(90 * 6, 90 * 8, 90, 90));
				}
			}

			counter++;
		}
		counter = 0;
		counter2 = 0;

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

		//create item in shop 
					pickup1.inShop = true ;
					pickup1.text.setFont(font);

					pickup1.isAtkyp = false;
					pickup1.isBoot = false;
					pickup1.isCoin = false;
					pickup1.isGlove = true;
					pickup1.isUlti = false;
					pickup1.isPotion = false;
					pickup1.isHeart = false;
					pickup1.sprite.setTexture(glove);
					pickup1.rect.setPosition(13 * blockSize + blockSize / 4, 11 * blockSize + blockSize / 4);
					pickup1.price = 15;
					pickup1.text.setString("price : " + to_string(pickup1.price));
					pickupArray.push_back(pickup1);
			
					pickup1.isAtkyp = false;
					pickup1.isBoot = false;
					pickup1.isCoin = false;
					pickup1.isGlove = false;
					pickup1.isUlti = true;
					pickup1.isPotion = false;
					pickup1.isHeart = false;
					pickup1.sprite.setTexture(ulti);
					pickup1.rect.setPosition(15 * blockSize + blockSize / 4, 11 * blockSize + blockSize / 4);
					pickup1.price = 45;
					pickup1.text.setString("price : " + to_string(pickup1.price));
					pickupArray.push_back(pickup1);
	
					pickup1.isAtkyp = false;
					pickup1.isBoot = true;
					pickup1.isCoin = false;
					pickup1.isGlove = false;
					pickup1.isUlti = false;
					pickup1.isPotion = false;
					pickup1.isHeart = false;
					pickup1.sprite.setTexture(boot);
					pickup1.rect.setPosition(17 * blockSize + blockSize / 4, 11 * blockSize + blockSize / 4);
					pickup1.price = 25;
					pickup1.text.setString("price : " + to_string(pickup1.price));
					pickupArray.push_back(pickup1);
					
		
					pickup1.isAtkyp = false;
					pickup1.isBoot = false;
					pickup1.isCoin = false;
					pickup1.isGlove = false;
					pickup1.isUlti = false;
					pickup1.isPotion = true;
					pickup1.isHeart = false;
					pickup1.sprite.setTexture(potion);
					pickup1.rect.setPosition(13 * blockSize + blockSize / 4, 9 * blockSize + blockSize / 4);
					pickup1.price = 20;
					pickup1.text.setString("price : " + to_string(pickup1.price));
					pickupArray.push_back(pickup1);
					
		
					pickup1.isAtkyp = true;
					pickup1.isBoot = false;
					pickup1.isCoin = false;
					pickup1.isGlove = false;
					pickup1.isUlti = false;
					pickup1.isPotion = false;
					pickup1.isHeart = false;
					pickup1.sprite.setTexture(atkup);
					pickup1.rect.setPosition(15 * blockSize + blockSize / 4, 9 * blockSize + blockSize / 4);
					pickup1.price = 25;
					pickup1.text.setString("price : " + to_string(pickup1.price));
					pickupArray.push_back(pickup1);
					
	
					pickup1.isAtkyp = false;
					pickup1.isBoot = false;
					pickup1.isCoin = false;
					pickup1.isGlove = false;
					pickup1.isUlti = false;
					pickup1.isPotion = false;
					pickup1.isHeart = true;
					pickup1.sprite.setTexture(heart);
					pickup1.rect.setPosition(17 * blockSize + blockSize/4 , 9 * blockSize + blockSize / 4);
					pickup1.price = 40;
					pickup1.text.setString("price : " + to_string(pickup1.price));
					pickupArray.push_back(pickup1);
					

					pickup1.inShop = false;
					pickup1.price = 0;
				






		// room 4 


		startX = (blockSize * 18);
		startY = (blockSize * 4);
		roomSize = 12 ;
		horizontaldoorup = 6;
		horizontaldoordown = 6;
		verticaldoorright = 6;
		verticaldoorleft = 6;
		wall1.destructable = false;

		counter = 0;
		while (counter < roomSize + 1)
		{
			counter2 = 0;
			while (counter2 < roomSize )
			{
				floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
				floorArray.push_back(floor1);
				counter2++;
			}
			counter++;
		}
		counter = 0;
		counter2 = 0; 

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

		//create things in room 4
		counter = 0;

		while (counter < (roomSize - 1))
		{
			counter2 = 0;
			while (counter2 < (roomSize - 2))
			{
				int tempRandom = generateRandom(20);

				if (tempRandom == 1 || tempRandom == 2 || tempRandom == 3)
				{
					//create random box 
					wall1.destructable = true;
					wall1.sprite.setTexture(barrel);
					wall1.sprite.setTextureRect(sf::IntRect(0, 180, 90, 90));
					wall1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					wall1.rect.setFillColor(sf::Color::Green);
					wallArray.push_back(wall1);
					wall1.sprite.setTexture(floor);
					wall1.sprite.setTextureRect(sf::IntRect(180, 360, 90, 90));

				}
				else if (tempRandom == 5)
				{
					//create enemy
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					enemyArray.push_back(enemy1);
				}

				else if (tempRandom == 6)
				{
					//create enemy
					enemy1.sprite.setTexture(slime);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					enemyArray.push_back(enemy1);
				}
				else if (tempRandom == 7)
				{
					//create enemy
					enemy1.sprite.setTexture(pigman);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					enemyArray.push_back(enemy1);
				}
				else if (tempRandom == 8)
				{
					//create enemy
					enemy1.sprite.setTexture(textureGhost);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					enemyArray.push_back(enemy1);
				}

				counter2++;
			}
			counter++;
		}
		counter = 0;
		counter2 = 0;
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

		counter = 0;
		while (counter < roomSize + 1  )
		{
			counter2 = 0;
			while (counter2 < roomSize )
			{
				if (counter != 2)
				{
					floor1.sprite.setTextureRect(sf::IntRect(90, 90 * 8, 90, 90));
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
					floor1.sprite.setTextureRect(sf::IntRect(90 * 6, 90 * 8, 90, 90));
				}
				
				else
				{
					
					floor1.sprite.setPosition((blockSize* counter) + startX, (blockSize* counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
				}
			}
			counter++;
		}
		counter = 0;
		counter2 = 0;


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
		horizontaldoordown = 4;
		verticaldoorright = 0;
		verticaldoorleft = 0;
		wall1.destructable = false ;

		counter = 0;
		while (counter < roomSize + 1  )
		{
			counter2 = 0;
			while (counter2 < roomSize )
			{
				floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY );
				floorArray.push_back(floor1);
			

				if (counter2 == 0 )
				{
					floor1.sprite.setTextureRect(sf::IntRect(90, 90 * 8, 90, 90));
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY );
					floorArray.push_back(floor1);
					counter2++;
					floor1.sprite.setTextureRect(sf::IntRect(90 * 6, 90 * 8, 90, 90));
				}
				else
				{
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY );
					floorArray.push_back(floor1);
					counter2++;
				}
			}
			counter++;
		}
		counter = 0;
		counter2 = 0;


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

		
		wall1.hp = 1000000 ;
		wall1.destructable = true;


		//room 7

		startX = (blockSize * 4);
		startY = (blockSize * 17 );
		roomSize = 9 ;
		horizontaldoorup = 6;
		horizontaldoordown = 0;
		verticaldoorright = 0;
		verticaldoorleft = 0;
		wall1.destructable = true;

		counter = 0;
		counter2 = 0;

		while (counter < roomSize - 1)//down
		{

			wall1.rect.setPosition((blockSize * counter) + startX, startY);
			wallArray.push_back(wall1);
			counter++;
		}
		counter = 0;

		wall1.destructable = false;
		startX = 0;
		startY = (blockSize * 23 );
		roomSize = 9;
		horizontaldoorup = 6;
		horizontaldoordown = 0;
		verticaldoorright = 0;
		verticaldoorleft = 0;
		wall1.destructable = false;

		counter2 = 0;
		counter = 0;

		while (counter < roomSize + 1)
		{
			counter2 = 0;
			while (counter2 < roomSize)
			{
				floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
				floorArray.push_back(floor1);


				if (counter == 1 || counter ==8 )
				{
					floor1.sprite.setTextureRect(sf::IntRect(90 * 7 , 90 * 8, 90, 90));
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
					floor1.sprite.setTextureRect(sf::IntRect(90 * 6, 90 * 8, 90, 90));
				}
				else if (counter2 == 1 || counter2 == 8)
				{
					floor1.sprite.setTextureRect(sf::IntRect(90 * 7, 90 * 8, 90, 90));
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
					floor1.sprite.setTextureRect(sf::IntRect(90 * 6, 90 * 8, 90, 90));
				}




				else
				{
					floor1.sprite.setPosition((blockSize * counter) + startX, (blockSize * counter2) + startY);
					floorArray.push_back(floor1);
					counter2++;
				}
			}
			counter++;
		}
		counter = 0;
		counter2 = 0;

		//build wall 7
		while (counter < roomSize + 3)//up
		{
			if (counter != horizontaldoorup)
			{
				wall1.rect.setPosition((blockSize * counter) + startX, startY);
				wallArray.push_back(wall1);
			}
			counter++;
		}
		counter = 0;

		while (counter < roomSize + 1)//down
		{

			wall1.rect.setPosition((blockSize * counter) + startX, startY + (blockSize * roomSize));
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

		//create things in room 7
		counter2 = 0;
		counter = 0;

		wall1.destructable = false;
		wallArray.push_back(wall1);

		while (counter < (roomSize - 1))
		{
			counter2 = 0;
			while (counter2 < (roomSize - 2))
			{
				int tempRandom = generateRandom(10);
				int bossM = 1;
				
				 if (tempRandom == 5)
				{
					//create enemy
					 enemy1.sprite.setTexture(texturePurplebat);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					enemyArray.push_back(enemy1);
				}

				else if (tempRandom == 8)
				{
					//create enemy
					enemy1.sprite.setTexture(textureGhost);
					enemy1.rect.setPosition((counter * blockSize) + startX + blockSize, (counter2 * blockSize) + blockSize + startY);
					enemyArray.push_back(enemy1);
				}
				
				counter2++;
			}
			counter++;
		}

		counter = 0;
		counter2 = 0;

	
	

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
		
						switch (event.type)
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
		
		window.clear(sf::Color(75,75,75));

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
			sf::Time elapsed7 = clock7.getElapsedTime();//time had play
			sf::Time elapsed8 = clock8.getElapsedTime();
			sf::Time elapsed9 = clock9.getElapsedTime();
			sf::Time elapsed10 = clock10.getElapsedTime();
			sf::Time elapsed11 = clock11.getElapsedTime();
			sf::Time elapsed12 = clock12.getElapsedTime();
			

			
			if (elapsed11.asSeconds() >= spawntime)
			{
				
				if (enemytype == 0)
				{
					enemy1.sprite.setTexture(texturePurplebat);
					enemyArray.push_back(enemy1);
				}
				else if (enemytype == 1)
				{
					enemy1.sprite.setTexture(textureGhost);
					enemyArray.push_back(enemy1);
				}
				else if (enemytype == 2)
				{
					enemy1.sprite.setTexture(slime);
					enemyArray.push_back(enemy1);
				}
				else if (enemytype == 3)
				{
					enemy1.sprite.setTexture(pigman);
					enemyArray.push_back(enemy1);
				}
				else if (enemytype == 4)
				{
					enemy1.sprite.setTexture(pigman);
					enemyArray.push_back(enemy1);
					enemy1.hp += 4 ;
					enemy1.attackdamge += 2 ;
					enemy1.dropScore += 5 ;
					collecter1 = enemy1.dropScore;
					mod1 = collecter1 % 2; 
						if (mod1 == 1)
						{
							pickup1.coinvalue += 1; 
							pickupArray.push_back(pickup1);
						}
				
				}
			
				int randspawn = generateRandom(10);
				//at room1
				enemy1.rect.setPosition(3 * 90, 3 * 90);
				enemyArray.push_back(enemy1);
				//at room2 top
				enemy1.rect.setPosition(8 * 90, 6 * 90);
				enemyArray.push_back(enemy1);
				//at room2 down
				enemy1.rect.setPosition(8 * 90, 11 * 90);
				enemyArray.push_back(enemy1);

	
				if (delayspawn == 4)
				{
					//at room4
					enemy1.rect.setPosition(22 * 90, 7 * 90);
					enemyArray.push_back(enemy1);
					//at room4
					enemy1.rect.setPosition(27 * 90, 10 * 90);
					enemyArray.push_back(enemy1);
					//at room4
					enemy1.rect.setPosition(20 * 90, 14 * 90);
					enemyArray.push_back(enemy1);
					//at room4
					enemy1.rect.setPosition(22 * 90, 12 * 90);
					enemyArray.push_back(enemy1);

				}
				clock11.restart();

				delayspawn++;
				if (enemytype > 4)
				{
					enemytype = 0;
				}
				
				enemytype++;
					if (enemytype > 4)
					{
						enemytype = 0;
					}
			}

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
			counter2 = 0;

			//destroy colied with wall
			for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
			{
				if (destroy1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
				{
					wallArray[counter].hp -= 1000000; 
					if (wallArray[counter].hp <= 0)
					{
						wallArray[counter].destroy = true;
						teleport += 1;
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

			counter = 0;
	
	
			//enemy aggro with player 
			if (Player1.Arrive == true)
			{
				counter = 0;
				for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
				{
					if (enemyArray[counter].aggro == true)
					{
						if (elapsed9.asSeconds() >= 1.25 )
						{
							clock9.restart();

							int tempRand = generateRandom(3);

							projectile1.movementSpeed = projectile1.movementSpeedforenemy;

							if (tempRand == 1)
							{
								projectile1.movementSpeed = 5 ;
								if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 270)) // player at the leftside of enemy 
								{
									soundShoot.play(); 
									projectile1.enemyprojectile = true; 
									projectile1.direction = 1; 
									projectile1.rect.setPosition(	enemyArray[counter].rect.getPosition().x + ( enemyArray[counter].rect.getSize().x ) / 2 - ( projectile1.rect.getSize().x / 2 ) , enemyArray[counter].rect.getPosition().y + (enemyArray[counter].rect.getSize().y) / 2 - (projectile1.rect.getSize().y / 2));
									projectileArray.push_back(projectile1);
									projectile1.enemyprojectile = false; 

									enemyArray[counter].direction = 1;
								}


								else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 270)) // player at the rightside of enemy 
								{
									soundShoot.play();
									projectile1.enemyprojectile = true;
									projectile1.direction = 2;
									projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + (enemyArray[counter].rect.getSize().x) / 2 - (projectile1.rect.getSize().x / 2), enemyArray[counter].rect.getPosition().y + (enemyArray[counter].rect.getSize().y) / 2 - (projectile1.rect.getSize().y / 2));
									projectileArray.push_back(projectile1);
									projectile1.enemyprojectile = false;

									enemyArray[counter].direction = 2;
								}

								else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 270)) // player at the upside of enemy 
								{
									soundShoot.play();
									projectile1.enemyprojectile = true;
									projectile1.direction = 3;
									projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + (enemyArray[counter].rect.getSize().x) / 2 - (projectile1.rect.getSize().x / 2), enemyArray[counter].rect.getPosition().y + (enemyArray[counter].rect.getSize().y) / 2 - (projectile1.rect.getSize().y / 2));
									projectileArray.push_back(projectile1);
									projectile1.enemyprojectile = false;

									enemyArray[counter].direction = 3;
								}
								else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 270)) // player at the upside of enemy 
								{
									soundShoot.play();
									projectile1.enemyprojectile = true;
									projectile1.direction = 4;
									projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + (enemyArray[counter].rect.getSize().x) / 2 - (projectile1.rect.getSize().x / 2), enemyArray[counter].rect.getPosition().y + (enemyArray[counter].rect.getSize().y) / 2 - (projectile1.rect.getSize().y / 2));
									projectileArray.push_back(projectile1);
									projectile1.enemyprojectile = false;

									enemyArray[counter].direction = 4;
								}
								projectile1.movementSpeed = projectile1.movementSpeedforplayer ;

							}
							else if (tempRand == 2)
							{
								if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
								{
									enemyArray[counter].direction = 1; 
								}
								else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
								{
									enemyArray[counter].direction = 2;
								}
								else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
								{
									enemyArray[counter].direction = 3;
								}
								else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
								{
									enemyArray[counter].direction = 4;
								}
								projectile1.movementSpeed = projectile1.movementSpeedforplayer;

							}
							else 
							{
								 if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
								{
									enemyArray[counter].direction = 3;
								}
								else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
								{
									enemyArray[counter].direction = 4;
								}
								else if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
								{
									enemyArray[counter].direction = 1;
								}
								else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
								{
									enemyArray[counter].direction = 2;
								}
								 projectile1.movementSpeed = projectile1.movementSpeedforplayer;

							}

							if (Player1.hp <= 0)
							{
								Player1.Arrive = false;
							}

						}
					}
						counter++;
				}
			}



			counter = 0;
			if (Player1.Arrive == true)
			{
				// key colied with player 
				counter = 0;
				for (iter24 = keyArray.begin(); iter24 != keyArray.end(); iter24++)
				{
					if (Player1.rect.getGlobalBounds().intersects(keyArray[counter].rect.getGlobalBounds()))
					{
						soundFin.play();
						textDisplay1.text.setFillColor(sf::Color::Black);
						textDisplay1.text.setString("key");
						textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
						textdisplayArray.push_back(textDisplay1);

						Player1.playerkey = true;
						keyArray[counter].picked = true;
					}
					counter++;
				}
			}
			if (Player1.playerkey == true)
			{
				destroy1.rect.setPosition(845 - 90, 1350 + 180);
			}


			else
			{
				//nothing 
			}

			counter = 0;
			counter2 = 0;

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

							pickupArray[counter].picked = true;
						}
						
						if (pickupArray[counter].inShop == true)
						{
							if (Player1.playermoney >= pickupArray[counter].price )
							{
								Player1.playermoney -= pickupArray[counter].price; 

								if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == true && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
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
									Player1.playerglove = true;
									projectile1.fastDelay -= 0.5;


								}


								else if (pickupArray[counter].isCoin == false  && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == true && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
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

								else if (pickupArray[counter].isCoin == false  && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == true && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
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
									textDisplay1.text.setString("boot of speed");
									Player1.movementSpeed += pickup1.bootspeed;
									projectile1.movementSpeed += pickup1.bootspeed;
									projectile1.movementSpeedforplayer += pickup1.bootspeed;
									textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
									textdisplayArray.push_back(textDisplay1);


								}

								else if (pickupArray[counter].isCoin == false &&  pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == true && pickupArray[counter].isHeart == false)
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
									Player1.maxHp += 10;

									textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
									textdisplayArray.push_back(textDisplay1);

								}

								pickupArray[counter].picked = true;
							}

							else
							{
							//	not enough money
							}
						}

						else if (pickupArray[counter].inShop == false)
						{
						if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == true && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == false && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
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
							Player1.playerglove = true;
							projectile1.fastDelay -= 0.5;


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

						else if (pickupArray[counter].isCoin == false && pickupArray[counter].isGlove == false && pickupArray[counter].isUlti == false && pickupArray[counter].isAtkyp == true && pickupArray[counter].isBoot == false && pickupArray[counter].isPotion == false && pickupArray[counter].isHeart == false)
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
							Player1.maxHp += 10;

							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 4 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);

						}

						else 
						{
						//nothing
						}
							pickupArray[counter].picked = true;


						}

					}
					counter++;
				}

				counter = 0;
			}
			counter = 0;



			// projectile hitted player 
			if (Player1.Arrive == true)
			{
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					if (projectileArray[counter].enemyprojectile == true)
					{
						if (projectileArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()))
						{
							soundHitted.play();
							projectileArray[counter].attackdamge = enemy1.attackdamge; 
							Player1.hp -= projectileArray[counter].attackdamge;
							if (Player1.hp <= 0)
							{
								Player1.Arrive = false;
							}
							projectileArray[counter].hit = true;

							// text show damge hitted  
							textDisplay1.text.setFillColor(sf::Color::Red);
							textDisplay1.text.setString(to_string(projectileArray[counter].attackdamge));
							textDisplay1.text.setPosition(Player1.rect.getPosition().x + (Player1.rect.getSize().x) * 2 / 5, Player1.rect.getPosition().y);
							textdisplayArray.push_back(textDisplay1);

						}
					}
					
					counter++;
				}
			}


			// delete projectile 
			counter = 0;

			// projectile hitted enemy 
			if (Player1.Arrive == true)
			{
				counter = 0;
				for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
				{
					counter2 = 0;
					for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
					{
						if (projectileArray[counter].enemyprojectile == false )
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
								enemyArray[counter2].aggro = true;
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
					Player1.SCORE += enemyArray[counter].dropScore ; 
				
					if (generateRandom0(enemyArray[counter].percentDropCoin) == 1 || generateRandom0(enemyArray[counter].percentDropCoin) == 0 )
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = true;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.isHeart = false; 
						pickup1.sprite.setTexture(coin);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);				
					}

					else if (generateRandom0(enemyArray[counter].percentDropGlove) == 2)
					{
						
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = true;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
						pickup1.sprite.setTexture(atkup);
						pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}
					else if (generateRandom0(enemyArray[counter].percentDropHeart) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.isHeart = true;
						pickup1.sprite.setTexture(heart);
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
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
						pickup1.isHeart = false;
						pickup1.sprite.setTexture(atkup);
						pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
						pickupArray.push_back(pickup1);
					}
					else if (generateRandom0(wallArray[counter].percentDropHeart) == 1)
					{
						pickup1.isAtkyp = false;
						pickup1.isBoot = false;
						pickup1.isCoin = false;
						pickup1.isGlove = false;
						pickup1.isUlti = false;
						pickup1.isPotion = false;
						pickup1.isHeart = true;
						pickup1.sprite.setTexture(heart);
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

			// delete picked key
			counter = 0;
			for (iter24 = keyArray.begin(); iter24 != keyArray.end(); iter24++)
			{
				if (keyArray[counter].picked == true)
				{
					keyArray.erase(iter24);
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

			//end the game 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				Player1.Arrive = false; 
			}

			//shooting 
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

			// draw floor
			counter = 0; 
			for (iter20 = floorArray.begin(); iter20 != floorArray.end(); iter20++)
			{
				//update pickup;
				//window.draw(floorArray[counter].rect);
				window.draw(floorArray[counter].sprite);
				counter++;
			}
			counter = 0;

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

			for (iter16 = wallArray.begin(); iter16 != wallArray.end(); iter16++)
			{
				//update pickup 
				wallArray[counter].updatewall();
				//window.draw(pickupArray[counter].rect);
				window.draw(wallArray[counter].sprite);
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

			// draw item
			for (iter12 = pickupArray.begin(); iter12 != pickupArray.end(); iter12++)
			{

				if (pickupArray[counter].inShop == true)
				{
					pickupArray[counter].updatepickup();
					pickupArray[counter].updatepickupPrice();
					window.draw(pickupArray[counter].text);
				}
				//update pickup 
				pickupArray[counter].updatepickup();
				//window.draw(pickupArray[counter].rect);
				window.draw(pickupArray[counter].sprite);
				counter++;
			}
			counter = 0;

			// draw key
			for (iter24 = keyArray.begin(); iter24 != keyArray.end(); iter24++)
			{

				//update pickup 
				keyArray[counter].updatepickup();
				window.draw(keyArray[counter].sprite);
			//	window.draw(keyArray[counter].rect);
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
				text.setPosition(Player1.rect.getPosition().x + 235, Player1.rect.getPosition().y + 335);
				text.setFillColor(sf::Color(250, 20, 0));
				text.setString("Player HP : " + to_string(Player1.hp));
				window.draw(text);
				text.setFillColor(sf::Color::White);

				//draw player max hp
				text.setPosition(Player1.rect.getPosition().x + 430, Player1.rect.getPosition().y + 335);
				text.setFillColor(sf::Color(175, 0, 0));
				text.setString(" \\ " + to_string(Player1.maxHp));
				window.draw(text);
				text.setFillColor(sf::Color::White);

				// draw player money 
				text.setPosition(Player1.rect.getPosition().x + 250, Player1.rect.getPosition().y - 300);
				text.setString("Player money : " + to_string(Player1.playermoney));
				
				// draw score 
				score.setPosition(Player1.rect.getPosition().x + 250, Player1.rect.getPosition().y - 335);
				score.setString("score :" + to_string(Player1.SCORE));

				window.draw(score);
				window.draw(text);
				clock10.restart();
				clock7.restart();
				clock8.restart();
	
			}



			//Player1 dead 
			else if (Player1.Arrive == false )
			{					
				
				Player1.rect.setPosition(window.getSize().x, window.getSize().y);

				if (elapsed8.asSeconds() >= 1)
				{
					menu.time -= 1;
					menu.countdown.setString(to_string(menu.time));
					clock8.restart();
				}

				window.clear();
			
				view1.setCenter(window.getSize().x/2, window.getSize().y / 2);
				window.setView(view1);

				if (elapsed7.asSeconds() <= 5 )
				{
					menu.draw2(window);
				}
				else
				{
					goto startgame;
				}
					
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

