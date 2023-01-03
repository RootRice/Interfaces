#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
#include "Panel_Element.h"
#include "Shape_Element.h"
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

	Panel(Panel_Properties& properties, unsigned int index_guide) : properties(properties), index_guide(index_guide) {};
	Panel(Panel_Properties& properties, unsigned int index_guide, std::deque<Shape_Element> elements) : properties(properties), index_guide(index_guide), elements(elements) {};
	Panel() { index_guide = 0; };
	char Take_Input(sf::Vector2u mouse_pos, sf::Event& button_presses);
	void Draw(sf::RenderWindow& window);

	void Add_Element(Shape_Element& element, bool back_or_front);
	void Add_Element(Shape_Element& element);
private:
	Panel_Properties properties;

	unsigned int index_guide;

	std::deque<Shape_Element> elements;
};

