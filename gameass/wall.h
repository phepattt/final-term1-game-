#pragma once
#include"entity.h"
#include"wall.h"


class wall : public entity
{
public:
	bool destructable = false;
	int hp = 10;
	int percentDropCoin = 10;
	int percentDropGlove = 2; 
	bool destroy = false; 
		
	wall();
	void updatewall();
};

