#pragma once
#include "entity.h"
class projectile : public entity
{
public:
	float movementSpeed = 5.5 ;
	float shootingspeed = 0.3 ;
	int attackdamge = 5;
	int direction = 0;
	bool hit = false ;
	int counterlifetime = 0;
	int lifetime = 50;
	int counter = 0; 
	int shootlimit = 9 ;
	float fastDelay = 6 ;

	projectile();
	void updateprojectile();
	void updateprojectileAnimation();

}
;
