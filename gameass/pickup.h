#pragma once
#include"entity.h"
#include"pickup.h"


class pickup : public entity
{
public:
	bool isCoin = false ; 
	bool isGlove = false ;
	bool picked = false;
	int coinvalue = 1;
	sf::Text pickedItem;
	pickup();

	void updatepickup();

};

