#pragma once
#include"entity.h"
#include"wall.h"


class wall : public entity
{
public:
	bool destructable = false;
	int hp = 5;

	int percentDropGlove = 30;
	int percentDropCoin = 8;
	int percentDropHeart = 60;
	int percentDropUlti = 70;
	int percentDropPotion = 30;
	int percentDropBoot = 40;
	int percentDropAtkup = 40;
	bool destroy = false; 
		
	wall();
	void updatewall();
};

