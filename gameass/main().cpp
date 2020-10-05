#include <stdio.h>
#include <iostream>
#include<SFML\Graphics.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "animation try 1", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.f));
	player.setFillColor(sf::Color::Cyan);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
					window.close();
					break; 
			case sf:: Event::Resized:
					printf("new window width : %i new window height : %i\n", evnt.size.width, evnt.size.height);
					break;
			}
		}
		window.draw(player);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(-0.5f, -0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.5f, 0.0f);
		}
	}


	return 0;
}