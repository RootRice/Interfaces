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
	struct Member_Function
	{
		void (Panel::* pointer)(sf::Vector2i& mouse_pos);
	};
	enum Functionality_Type
	{
		On_Click, On_Hold, On_Release, None
	};
	virtual void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) = 0;
	virtual void Take_Input(sf::Vector2i& mouse_pos, sf::Vector2f panel_pos, Panel& p, sf::Event& button_presses);
	virtual void Add_Functionality(Functionality_Type type, Member_Function m);

	virtual bool Check_Within_Bounds(sf::Vector2f& panel_origin, sf::Vector2f point);
protected:
	Element_Properties properties;

	bool button_held;
	std::vector<Member_Function> on_click;
	std::vector<Member_Function> on_hold;
	std::vector<Member_Function> on_release;

	Panel_Element() : button_held(false) {};
};

