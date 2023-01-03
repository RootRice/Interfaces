#include "Panel.h"

char Panel::Take_Input(sf::Vector2u mouse_pos, sf::Event& button_presses)
{

	return 0;
}

void Panel::Draw(sf::RenderWindow& window)
{
	sf::Vector2f window_size(window.getSize());
	sf::View ui_view(window_size * 0.5f, window_size);
	sf::View current_view = window.getView();

	constexpr unsigned int anchor_count = 9;
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
	sf::Vector2f position = properties.position + anchors[properties.anchor];

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
		elements.push_back(element); return;

	elements.push_front(element);
}

void Panel::Add_Element(Shape_Element& element)
//assumes placed at back
{
	elements.push_back(element);
}
