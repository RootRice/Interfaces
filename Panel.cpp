#include "Panel.h"

Panel::Panel(Panel_Properties& properties, sf::RenderWindow& window) : properties(properties), window(window) 
{
	
	if (properties.moveable)
	{
		const float move_bar_width = properties.size.x - (properties.size.x * 0.10f);
		const float move_bar_height = 10.0f;
		Panel_Element::Element_Properties element_properties{ sf::Vector2f(move_bar_width, move_bar_height), sf::Vector2f(0.0f, 0.0f),  sf::Vector2f(0.0f, 0.0f) };
		Shape_Element shape(sf::Color::Blue, element_properties);
		Add_Element(shape, true);
		const int last_element = elements.size() - 1;
		void (Panel::*function_pointer)(sf::Vector2u&) = &Panel::Begin_Move;
		elements[last_element].Add_Functionality(Panel_Element::On_Click, function_pointer);
		function_pointer = &Panel::Move;
		elements[last_element].Add_Functionality(Panel_Element::On_Hold, function_pointer);
		function_pointer = &Panel::End_Move;
		elements[last_element].Add_Functionality(Panel_Element::On_Release, function_pointer);
	}
}


char Panel::Take_Input(sf::Vector2f mouse_pos, sf::Event& button_presses)
{
	int num_elements = elements.size();
	for (int i = 0; i < num_elements; i++)
	{
		if (elements[i].Check_Within_Bounds(properties.position, mouse_pos))
		{
			sf::Vector2u v2(mouse_pos.x, mouse_pos.y);
			elements[i].Take_Input(v2, *this,button_presses);
		}
	}
	return 0;
}

void Panel::Draw()
{
	sf::Vector2f window_size(window.getSize());
	sf::View ui_view(window_size * 0.5f, window_size);
	sf::View current_view = window.getView();

	sf::Vector2f position = Get_Position_In_Window();

	window.setView(ui_view);
	const unsigned int num_elements = elements.size();
	for (int i = 0; i < num_elements; i++)
	{
		elements[i].Draw(window, position);
	}
	

	window.setView(current_view);
}

void Panel::Add_Element(Shape_Element& element, bool back_or_front)
{
	if (back_or_front)
	{
		elements.push_back(element);
		return;
	}
		

	elements.push_front(element);
}

void Panel::Add_Element(Shape_Element& element)
//assumes placed at back
{
	elements.push_back(element);
}

bool Panel::Check_Within_Bounds(sf::Vector2f point)
{
	sf::Vector2f adjusted_position = Get_Position_In_Window();
	const sf::Vector2f top_left = adjusted_position;
	const sf::Vector2f bottom_right = adjusted_position + properties.size;
	bool tl = false;
	bool br = false;
	tl = (point.x > top_left.x) & (point.y > top_left.y);
	br = (point.x < bottom_right.x) & (point.y < bottom_right.y);
	return tl & br;
}

sf::Vector2f Panel::Get_Position_In_Window()
{
	constexpr unsigned int anchor_count = 9;
	sf::Vector2f window_size(window.getSize());
	sf::Vector2f anchors[anchor_count]
	{
		sf::Vector2f(0, 0),
		sf::Vector2f(window_size.x / 2, 0),
		sf::Vector2f(window_size.x, 0),
		sf::Vector2f(window_size.x, window_size.y / 2),
		sf::Vector2f(window_size.x, window_size.y),
		sf::Vector2f(window_size.x / 2, window_size.y),
		sf::Vector2f(0, window_size.y),
		sf::Vector2f(0, window_size.y / 2),
		sf::Vector2f(window_size * 0.5f)
	};
	sf::Vector2f r = properties.position + anchors[properties.anchor];
	return properties.position + anchors[properties.anchor];
}

void Panel::Begin_Move(sf::Vector2u& mouse_pos)
{
	sf::Vector2f offset = properties.position - sf::Vector2f(mouse_pos);
	tracker = new Mouse_Hold_Tracker(mouse_pos, offset);
}

void Panel::Move(sf::Vector2u& mouse_pos)
{
	tracker->Update_Mouse_Position(mouse_pos);
	properties.position = tracker->Get_Updated_Position();
}

void Panel::End_Move(sf::Vector2u& mouse_pos)
{
	tracker = NULL;
}

