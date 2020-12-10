#pragma once
#include "entity.h"
#include<SFML\Graphics.hpp>

class textDisplay : public entity 
{
public : 
	int movementspeed = 1 ;
	int counter = 0 ;
	int lifetime = 30 ;
	bool destroy = false;
	string myString = "default ";

	textDisplay();
	void updateTextdisplay(); 
	
};

