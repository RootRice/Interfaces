#pragma once
#include "SFML/Graphics.hpp"
class Panel_Element
{
public:
	struct Element_Properties
	{
		sf::Vector2f size;
		sf::Vector2f origin;
		sf::Vector2f position;
	};
	virtual void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) = 0;
	virtual void Take_Input(sf::Vector2u& mouse_pos, sf::Event& button_presses) = 0;
protected:
	Element_Properties properties;
	Panel_Element() {};
};

