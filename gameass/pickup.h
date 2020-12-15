#pragma once
#include"entity.h"
#include"pickup.h"


class pickup : public entity
{
public:
	bool isCoin = false ; 
	bool isGlove = false ;
	bool picked = false;
	bool isPotion = false; 
	bool isBoot = false; 
	bool isUlti = false; 
	bool isAtkyp = false;
	bool isHeart = false;

	int coinvalue   =  1 ;
	int heartValue = 40 ;
	int gloveValue  = 10 ;
	int potionValue = 20 ; 
	int bootValue   = 25 ;
	int atkupValue	= 25;
	int ultiValue   = 45 ;

	int heart = 10; 
	int atkup = 1;
	int heal = 10;

	float bootspeed = 0.25;
	sf::Text pickedItem;
	pickup();

	void updatepickup();

};

