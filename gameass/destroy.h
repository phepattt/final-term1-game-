#pragma once
#include "entity.h"
class destroy : public entity
{
public:
	float movementSpeed = 0.1 ;
	int attackdamge = 1000000;
	int direction = 4;
	int lifetime = 100000;
	

	destroy();
}
;
