#pragma once
#include "entity.h"
#include "player.h"
class ghost : public player
{
public:
	int i = 0;
	int movementSpeed = 1;
	int attackdamge = 5;
	int counterwalk = 0;
	int percentDropCoin = 2;
	int hp = 10;
	int chasetime = 1000;
	bool arrive = true;
	sf::Vector2f playerposition; 
	sf::Vector2f ghostposition;
	ghost();

	void updateghost();
	void updatemovementghost();
	void updaterealtime();


};

