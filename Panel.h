#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
#include "Panel_Element.h"
#include "Shape_Element.h"
#include "Mouse_Hold_Tracker.h"
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
		sf::Vector2f size;
		anchor_point anchor;
		bool moveable;
		bool closeable;
	};

	Panel(Panel_Properties& properties, sf::RenderWindow& window);
	Panel(Panel_Properties& properties, std::deque<Shape_Element> elements, sf::RenderWindow& window) : properties(properties), elements(elements), window(window) {};

	~Panel() { tracker = NULL; delete tracker; };

	char Take_Input(sf::Vector2f mouse_pos, sf::Event& button_presses);
	void Draw();

	void Add_Element(Shape_Element& element, bool back_or_front);
	void Add_Element(Shape_Element& element);

	bool Check_Within_Bounds(sf::Vector2f point);

	void Begin_Move(sf::Vector2i& mouse_pos);
	void Move(sf::Vector2i& mouse_pos);
	void End_Move(sf::Vector2i& mouse_pos);
	void Close(sf::Vector2i& mouse_pos);
private:
	Panel_Properties properties;

	sf::RenderWindow& window;
	sf::Vector2f Get_Position_In_Window();

	Mouse_Hold_Tracker* tracker = NULL;

	std::deque<Shape_Element> elements;

	bool should_close = false;
	
};

