#pragma once
#include "entity.h"
#include "random.h"
class enemy : public entity
{
public :
	int movementSpeed = 1;
	int movementlength = 100; 
	int attackdamge = 5;
	int counterwalk = 0;
	int direction = 4;
	int counter = 0  ;
	int mod = 10 ;
	int push = 3;
	int percentDropGlove = 10; 
	int percentDropCoin = 4; 
	int hp = 20; 
	bool arrive = true ; 
	bool enemycanmoveup = true;
	bool enemycanmovedown = true;
	bool enemycanmoveright = true;
	bool enemycanmoveleft = true;

	enemy();

	void updateenemy();
	void updatemovementenemy();


};

