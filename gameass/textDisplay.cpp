#include "textDisplay.h"

textDisplay::textDisplay()
{
	text.setFillColor(sf::Color::Red);
	text.setPosition(300, 300);
	text.setCharacterSize(15);
	text.setString(myString);
}
void textDisplay::updateTextdisplay() 
{
	text.move(0, -movementspeed);
	counter++;

	if (counter >= lifetime)
	{
		destroy = true ;
	}
	
}
