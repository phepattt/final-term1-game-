#pragma once
#include"entity.h"
#include"player.h"


class player : public entity 
{
public :
	float movementSpeed = 5 ;
	int attackdamge = 5; 
	int counterwalk = 0; 
	int direction = 4 ; 
	int hp = 50 ; 
	int maxHp = 50; 
	int playermoney = 0;
	int push = 6 ;  
	int SCORE = 0; 
	bool playerulti = true; 
	bool Arrive = false;
	bool playerglove = false;
	bool playercanmoveup = true;
	bool playercanmovedown = true; 
	bool playercanmoveleft = true; 
	bool playercanmoveright = true;
	bool playerkey = false;

	sf::Vector2f Player1Position ;
	sf::RectangleShape coffin1;
	sf::Time countDownTime; 
	sf::Clock clockCountdown; 

	player();
	void updatetimeritem() ; 
	void update();
	void updatemovement();


};

