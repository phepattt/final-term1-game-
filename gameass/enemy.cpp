#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(48, 70));
	rect.setPosition(600, 360);
	rect.setFillColor(sf::Color::Red);
	sprite.setPosition(540, 360);
	sprite.setTextureRect(sf::IntRect(0, 0, 48, 70));

}

void enemy::updateenemy()
{
	sprite.setPosition(rect.getPosition());
}


void enemy::updatemovementenemy() 
{
	if (direction == 1)
	{
		if (enemycanmoveleft == true)
		{
			direction = 1;
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(48 * counterwalk, 70 * 1, 48, 70));
			enemycanmovedown = true;
			enemycanmoveleft = true;
			enemycanmoveright = true;
			enemycanmoveup = true;
		}
	
	}
	
	 else if (direction == 2)
		{
			if (enemycanmoveright == true)
				{
				direction = 2;
					rect.move(movementSpeed, 0);
					sprite.setTextureRect(sf::IntRect(48 * counterwalk, 70 * 2, 48, 70));
					enemycanmovedown = true;
					enemycanmoveleft = true;
					enemycanmoveright = true;
					enemycanmoveup = true;
			}


		}
	
	 else if (direction == 3)
	 {
		 if (enemycanmoveup == true)
		 {
			 direction = 3;
			 rect.move(0, -movementSpeed);
			 sprite.setTextureRect(sf::IntRect(48 * counterwalk, 70 * 3, 48, 70));
			 enemycanmovedown = true;
			 enemycanmoveleft = true;
			 enemycanmoveright = true;
			 enemycanmoveup = true;
		 }

	
	 }
		
	
	else if (direction == 4)
	{
		 if (enemycanmovedown == true)
		{
			 direction = 4; 
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(48 * counterwalk, 70 * 0, 48, 70));
			enemycanmovedown = true;
			enemycanmoveleft = true;
			enemycanmoveright = true;
			enemycanmoveup = true;
		 }

	}
		
	else
	{
		// not moving 
	}

	counter++; 

	if (counter >= movementlength)
	{
		counter = 0;
		direction = generateRandom(mod);
	}
	

}