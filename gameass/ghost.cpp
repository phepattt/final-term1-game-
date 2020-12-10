#include "ghost.h"
ghost::ghost()
{
	rect.setSize(sf::Vector2f(49, 71));
	rect.setPosition(700, 500);
	rect.setFillColor(sf::Color::White);
	sprite.setPosition(700, 500);
	sprite.setTextureRect(sf::IntRect(0, 0, 49, 71));
	
}
void ghost::updateghost()
{
	sprite.setPosition(rect.getPosition());

}
void ghost::updatemovementghost()
{
		if(rect.getPosition().x != Player1Position.x)
		{
			if (rect.getPosition().x > Player1Position.x)
			{
				rect.move(-movementSpeed, 0);
				sprite.setTextureRect(sf::IntRect(49 * counterwalk, 71 * 1, 49, 71));
			}
			else
			{
				rect.move(movementSpeed, 0);
				sprite.setTextureRect(sf::IntRect(49 * counterwalk, 71 * 2, 49, 71));
			}
		}
		if (rect.getPosition().y != Player1Position.y)
		{
			if (rect.getPosition().y > Player1Position.y)
			{
				rect.move(0, -movementSpeed);
				sprite.setTextureRect(sf::IntRect(49 * counterwalk, 71 * 3, 49, 71));
			}
			else
			{
				rect.move(0, movementSpeed);
				sprite.setTextureRect(sf::IntRect(49 * counterwalk, 71 * 0, 49, 71));
			}
		}
		playerposition = Player1Position;
}
