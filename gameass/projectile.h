#pragma once
#include "entity.h"
class projectile : public entity
{
public:
	float movementSpeed = 3.5 ;
	float shootingspeed = 0.1 ;
	int attackdamge = 5;
	int direction = 0;
	bool hit = false ;
	int counterlifetime = 0;
	int lifetime = 1000;
	int counter = 0; 

	projectile();
	void updateprojectile();
	void updateprojectileAnimation();

}
;
