#pragma once
#include"entity.h"
#include"wall.h"


class wall : public entity
{
public:
	bool destructable = false;
	int hp = 5;

	int percentDropGlove = 3;
	int percentDropCoin = 3;
	int percentDropHeart = 6 ;
	int percentDropUlti = 8 ;
	int percentDropPotion = 3;
	int percentDropBoot = 3;
	int percentDropAtkup = 3;
	bool destroy = false; 
		
	wall();
	void updatewall();
	void destroydoor();
	void builddoor();
};

