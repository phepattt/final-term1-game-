#pragma once
#include"entity.h"
#include"player.h"


class player : public entity 
{
public :
	float movementSpeed = 8;
	int attackdamge = 5; 
	int counterwalk = 0; 
	int direction = 4 ; 
	int hp = 20 ; 
	int playermoney = 0;
	int push = 7 ;  
	bool playerulti = true; 
	bool Arrive = true;
	bool playerglove = false;
	bool playercanmoveup = true;
	bool playercanmovedown = true; 
	bool playercanmoveleft = true; 
	bool playercanmoveright = true;

	sf::Vector2f Player1Position ;
	sf::RectangleShape coffin1;
	sf::Time countDownTime; 
	sf::Clock clockCountdown; 

	player();
	void updatetimeritem() ; 
	void update();
	void updatemovement();


};

