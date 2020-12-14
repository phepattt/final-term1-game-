#include "pickup.h"

pickup::pickup()
{
	rect.setOrigin(-15, -15);
	rect.setSize(sf::Vector2f(20, 20));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
	sprite.setPosition(0, 0); 
};

void pickup::updatepickup()
{
	sprite.setPosition(rect.getPosition());
};
