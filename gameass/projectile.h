#pragma once
#include "entity.h"
class projectile : public entity
{
public:
	float movementSpeed = 8.5 ;
	float shootingspeed = 0.3 ;
	int attackdamge = 10 ;
	int bossATK = 10; 
	int direction = 0;
	bool hit = false ;
	int counterlifetime = 0;
	int lifetime = 100 ;
	int counter = 0; 
	int shootlimit = 9 ;
	float fastDelay = 6 ;
	bool enemyprojectile = false;
	bool playerprojectile = true ;

	projectile();
	void updateprojectile();
	void updateprojectileAnimation();

}
;
