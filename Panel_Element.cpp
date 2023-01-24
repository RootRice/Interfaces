#include "Panel_Element.h"

void Panel_Element::Add_Functionality(Functionality_Type type, void (Panel::* function_pointer)(sf::Vector2u&))
{
	switch (type)
	{
	case(On_Click):
		on_click.push_back(function_pointer);
		break;
	case(On_Hold):
		on_hold.push_back(function_pointer);
		break;
	case(On_Release):
		on_release.push_back(function_pointer);
		break;
	default:
		break;
	}
}

void Panel_Element::Take_Input(sf::Vector2u& mouse_pos, Panel& p, sf::Event& button_presses)
{
	switch (button_presses.type)
	{
	case(sf::Event::MouseButtonPressed):
	{
		button_held = true;
		int num_functions = on_click.size();
		for (int i = 0; i < num_functions; i++) (p.*on_click[i])(mouse_pos);
		break;
	}
	case(sf::Event::MouseButtonReleased):
	{
		button_held = false;
		int num_functions = on_release.size();
		for (int i = 0; i < num_functions; i++) (p.*on_release[i])(mouse_pos);
		break;
	}
	}
	if (button_held)
	{
		int num_functions = on_hold.size();
		for (int i = 0; i < num_functions; i++) (p.*on_hold[i])(mouse_pos);
	}
}

bool Panel_Element::Check_Within_Bounds(sf::Vector2f& panel_origin, sf::Vector2f point)
{
	sf::Vector2f adjusted_position = panel_origin + properties.position;
	const sf::Vector2f top_left = adjusted_position;
	const sf::Vector2f bottom_right = adjusted_position + properties.size;
	bool tl = false;
	bool br = false;
	tl = (point.x > top_left.x) & (point.y > top_left.y);
	br = (point.x < bottom_right.x) & (point.y < bottom_right.y);
	return tl & br;
}
