#pragma once
#include<SFML\Graphics.hpp>
#define MAX_NUMBER_OF_STRING 2
#include "entity.h"
class menu : public entity 
{
public:
	sf::RectangleShape bg1;
	sf::RectangleShape behindtext;
	bool enterplay = false;
	bool musicplay = true;
	int atText = -1 ;
	menu(float width, float height);
	~menu();

	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();

private:
	int selectStringIndex;
	sf::Texture menuBgTexture;
	sf::Font font;
	sf::Font font2;
	sf::Text text[MAX_NUMBER_OF_STRING];
	sf::Text gamename;
};

