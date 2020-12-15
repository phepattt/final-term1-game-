#include "menu.h"

menu::menu(float width,float height )
{
	//setup
	behindtext.setSize(sf::Vector2f(width *2 /4, height*4/10));
	behindtext.setPosition(sf::Vector2f(width * 1 / 4, height * 4.5 / 10));
	behindtext.setFillColor(sf::Color(178,0,0));

	menuBgTexture.loadFromFile("bgmenu1.jpg");
	bg1.setSize(sf::Vector2f(width, height));
	bg1.setTexture(&menuBgTexture);
	font.loadFromFile("font.ttf");
	font2.loadFromFile("gamenamefont.ttf");

	// game name 
	gamename.setFont(font2);
	gamename.setFillColor(sf::Color::Black);
	gamename.setString("LegendAdventure");
	gamename.setCharacterSize(135);
	gamename.setPosition(sf::Vector2f((width / 9)  , (height / 5 )));

	//box 1
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::White);
	text[0].setString("PLAY");
	text[0].setCharacterSize(30);
	text[0].setPosition(sf::Vector2f((width / 2)- (behindtext.getSize().x) / 7 , (height * 5) / 10));
	
	//box 2
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("EXIT");
	text[1].setCharacterSize(30);
	text[1].setPosition(sf::Vector2f((width / 2)- (behindtext.getSize().x) / 7 , (height * 6) / 10));

	selectStringIndex = 0;

	
}

menu:: ~menu()
{

}

void menu::draw(sf::RenderWindow& window)
{
	
	window.draw(bg1);
	window.draw(behindtext);
	window.draw(gamename);
	for (int i = 0 ; i < MAX_NUMBER_OF_STRING; i++)
	{
		window.draw(text[i]);
	}
}

void menu::drawDEAD(sf::RenderWindow& window)
{

	window.draw(bg1);
	window.draw(behindtext);
	window.draw(gamename);
	for (int i = 0; i < MAX_NUMBER_OF_STRING; i++)
	{
		window.draw(text[i]);
	}
}


void menu::moveup()
{

		text[0].setFillColor(sf::Color(166, 166, 166));
		text[1].setFillColor(sf::Color::White);
}
void menu::movedown()
{
		text[1].setFillColor(sf::Color(166, 166, 166));
		text[0].setFillColor(sf::Color::White);
}