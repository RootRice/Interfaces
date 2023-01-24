#pragma once
#include "SFML/Graphics.hpp"
#include <functional>
class Panel;

class Panel_Element
{
public:
	struct Element_Properties
	{
		sf::Vector2f size;
		sf::Vector2f origin;
		sf::Vector2f position;
	};
	enum Functionality_Type
	{
		On_Click, On_Hold, On_Release, None
	};
	virtual void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) = 0;
	void Take_Input(sf::Vector2u& mouse_pos, Panel& p, sf::Event& button_presses);
	void Add_Functionality(Functionality_Type type, void (Panel::* function_pointer)(sf::Vector2u&));

	virtual bool Check_Within_Bounds(sf::Vector2f& panel_origin, sf::Vector2f point);
protected:
	Element_Properties properties;

	bool button_held;
	std::vector<void (Panel::*)(sf::Vector2u&)> on_click;
	std::vector<void (Panel::*)(sf::Vector2u&)> on_hold;
	std::vector<void (Panel::*)(sf::Vector2u&)> on_release;

	Panel_Element() {};
};

