#include "projectile.h"
projectile::projectile()
{
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Cyan);
	sprite.setOrigin(15,15);
	sprite.setTextureRect(sf::IntRect(0 , 0, 67, 42));
	sprite.setPosition(0, 0);
};
void projectile::updateprojectile()
{
	if (direction == 1)
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(67 * counter, 42 * 1, 67, 42));
	}
	else if (direction == 2)
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(67 * counter, 42 * 0, 67, 42));
	}
	else if (direction == 3)
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(67 * counter, 42 * 2, 67, 42));
	}
	else if (direction == 4)
	{
		rect.move(0, +movementSpeed);
		sprite.setTextureRect(sf::IntRect(67 * counter, 42 * 4, 67, 42));
	}

	

	counterlifetime++;
	if (counterlifetime >= lifetime)
	{
		hit = true;
	}
};
void projectile::updateprojectileAnimation()
{
	sprite.setPosition(rect.getPosition());
}