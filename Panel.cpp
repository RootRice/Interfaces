#include "Panel.h"
#include <algorithm>

Panel::Panel(Panel_Properties& properties, sf::RenderWindow& window) : properties(properties), window(window) 
{
	
	if (properties.moveable)
	{
		const float move_bar_width = properties.size.x - (properties.size.x * 0.10f);
		const float move_bar_height = 10.0f;
		Panel_Element::Element_Properties move_bar_properties{ sf::Vector2f(move_bar_width, move_bar_height), sf::Vector2f(0.0f, 0.0f),  sf::Vector2f(0.0f, 0.0f) };
		Shape_Element shape(sf::Color::Blue, move_bar_properties);
		Add_Element(shape, true);
		const int last_element = elements.size() - 1;
		elements[last_element].Add_Functionality(Panel_Element::On_Click, Panel_Element::Member_Function{ &Panel::Begin_Move });
		elements[last_element].Add_Functionality(Panel_Element::On_Hold, Panel_Element::Member_Function{ &Panel::Move });
		elements[last_element].Add_Functionality(Panel_Element::On_Release, Panel_Element::Member_Function{ &Panel::End_Move });
	}
	if (properties.closeable)
	{
		const float close_box_width = properties.size.x * 0.10f;
		const float close_box_height = 10.0f;
		Panel_Element::Element_Properties close_box_properties{ sf::Vector2f(close_box_width, close_box_height), sf::Vector2f(0.0f, 0.0f),  sf::Vector2f(properties.size.x - close_box_width, 0.0f) };
		Shape_Element shape(sf::Color::Red, close_box_properties);
		Add_Element(shape, true);
		const int last_element = elements.size() - 1;
		elements[last_element].Add_Functionality(Panel_Element::On_Release, Panel_Element::Member_Function{ &Panel::Close });
	}
}


char Panel::Take_Input(sf::Vector2f mouse_pos, sf::Event& button_presses)
{
	int num_elements = elements.size();
	for (int i = 0; i < num_elements; i++)
	{
		sf::Vector2i v2(mouse_pos.x, mouse_pos.y);
		elements[i].Take_Input(v2, properties.position, *this, button_presses);
	}
	return should_close;
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

void Panel::Begin_Move(sf::Vector2i& mouse_pos)
{
	sf::Vector2f offset = properties.position - sf::Vector2f(mouse_pos);
	tracker = new Mouse_Hold_Tracker(mouse_pos, offset);
}

void Panel::Move(sf::Vector2i& mouse_pos)
{
	tracker->Update_Mouse_Position(mouse_pos);
	properties.position = tracker->Get_Updated_Position();
	properties.position.x = std::max(properties.position.x, 10.0f);
	properties.position.y = std::max(properties.position.y, 10.0f);
	properties.position.x = std::min(properties.position.x, window.getSize().x - 10.0f);
	properties.position.y = std::min(properties.position.y, window.getSize().y - 10.0f);
}

void Panel::End_Move(sf::Vector2i& mouse_pos)
{
	delete tracker;
}

void Panel::Close(sf::Vector2i& mouse_pos)
{
	should_close = true;
}

