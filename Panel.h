#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
#include "Panel_Element.h"
class Panel
{
public:
	enum anchor_point
	{
		top_left, top, top_right, right, bottom_right, bottom, bottom_left, left, center
	};
	struct Panel_Properties
	{
		sf::Vector2f position;
		anchor_point anchor;
	};

	Panel(sf::RenderWindow& window, Panel_Properties properties, unsigned int index_guide) : window(window), properties(properties), index_guide(index_guide) {};
	Panel(sf::RenderWindow& window, Panel_Properties properties, unsigned int index_guide, std::deque<Panel_Element> elements) : window(window), properties(properties), index_guide(index_guide), elements(elements) {};

	char Take_Input(sf::Vector2u mouse_pos, sf::Event& button_presses);
	void Draw();

	void Add_Element(Panel_Element& element, bool back_or_front);
	void Add_Element(Panel_Element& element);
private:
	sf::RenderWindow& window;
	Panel_Properties properties;

	unsigned int index_guide;

	std::deque<Panel_Element> elements;
};

