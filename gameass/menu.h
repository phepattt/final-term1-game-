#pragma once
#include<SFML\Graphics.hpp>
#define MAX_NUMBER_OF_STRING 2
#include "entity.h"
class menu : public entity 
{
public:
	sf::RectangleShape bg1;
	sf::RectangleShape bg2;
	sf::RectangleShape behindtext;
	sf::Text countdown;
	bool enterplay = false;
	bool musicplay = true;
	int time = 5 ; 
	int atText = -1 ;
	menu(float width, float height);
	~menu();

	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();
	void draw2(sf::RenderWindow& window);

private:
	sf::Text endgame; 
	int selectStringIndex;
	sf::Texture menuBgTexture;
	sf::Texture menuBgTexture2;
	sf::Font font;
	sf::Font font2;
	sf::Text text[MAX_NUMBER_OF_STRING];
	sf::Text gamename;
	sf::Text name;
};

