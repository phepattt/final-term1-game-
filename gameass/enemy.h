#pragma once
#include "entity.h"
#include "random.h"
class enemy : public entity
{
public :
	int movementSpeed = 2;
	int movementlength = 100; 
	int attackdamge = 2 ;
	int counterwalk = 0;
	int direction = 0 ;
	int counter = 0  ;
	int mod = 10 ;
	int push = 4 ;
	int dropScore = 10; 
	int percentDropGlove = 5; 
	int percentDropHeart = 10;
	int percentDropCoin = 2 ; 
	int percentDropUlti = 10 ; 
	int percentDropPotion = 8 ;
	int percentDropBoot = 10   ;
	int percentDropAtkup = 8 ;
	
	int hp = 20; 
	bool arrive = true ; 
	bool enemycanmoveup = true;
	bool enemycanmovedown = true;
	bool enemycanmoveright = true;
	bool enemycanmoveleft = true;
	bool aggro = false; 
	enemy();

	void updateenemy();
	void updatemovementenemy();


};

