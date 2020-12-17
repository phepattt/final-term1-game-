#include "pickup.h"

pickup::pickup()
{
	rect.setOrigin(-15, -15);
	rect.setSize(sf::Vector2f(20, 20));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Yellow);
	sprite.setPosition(0, 0); 
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::Cyan);

};

void pickup::updatepickup()
{
	sprite.setPosition(rect.getPosition());
};

void pickup::updatepickupPrice()
{
	text.setPosition(rect.getPosition().x -30 , rect.getPosition().y + 35);
}
