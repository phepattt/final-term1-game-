#include "player.h"

player::player()
{
	
	rect.setSize(sf::Vector2f(44, 64));
	rect.setPosition(210, 210);
	rect.setFillColor(sf::Color::White);
	sprite.setOrigin(5, 5);
	sprite.setPosition(210, 210);
	sprite.setTextureRect(sf::IntRect(0, 0, 52, 69));
	coffin1.setSize(sf::Vector2f(52,69));

}

void player::update()
{
	sprite.setPosition(rect.getPosition());
	Player1Position = rect.getPosition();
}

void player::updatemovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (playercanmoveleft == true)
		{
			direction = 1;
			rect.move(-movementSpeed, 0.0f);
			
			sprite.setTextureRect(sf::IntRect(52 * counterwalk, 69 * 1, 52, 69));
			
		}
		playercanmovedown = true;
		playercanmoveleft = true;
		playercanmoveright = true;
		playercanmoveup = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		if (playercanmoveright == true)
		{
			direction = 2;
			rect.move(movementSpeed, 0.0f);
			sprite.setTextureRect(sf::IntRect(52 * counterwalk, 69 * 2, 52, 69));
		}
	
		playercanmovedown = true;
		playercanmoveleft = true;
		playercanmoveright = true;
		playercanmoveup = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{ 
		if (playercanmoveup == true)
		{
			direction = 3;
			rect.move(0.0f, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(52 * counterwalk, 69 * 3, 52, 69));
		}
		
		playercanmovedown = true;
		playercanmoveleft = true;
		playercanmoveright = true;
		playercanmoveup = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (playercanmovedown == true) 
		{
			direction = 4;
			rect.move(0.0f, movementSpeed);
			sprite.setTextureRect(sf::IntRect(52 * counterwalk, 69 * 0, 52, 69));
		}

		playercanmovedown = true;
		playercanmoveleft = true;
		playercanmoveright = true;
		playercanmoveup = true;
	}
	else
	{

	}
	
	

}
