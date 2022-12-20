#include "Panel.h"

char Panel::Take_Input(sf::Vector2u mouse_pos, sf::Event& button_presses)
{

	return 0;
}

void Panel::Draw()
{
	sf::Vector2f window_size(window.getSize());
	sf::View ui_view(window_size * 0.5f, window_size);
	sf::View current_view = window.getView();

	window.setView(ui_view);

	//Stuff

	window.setView(current_view);
}

void Panel::Add_Element(Panel_Element& element, bool back_or_front)
{
	if (back_or_front)
		elements.push_back(element); return;

	elements.push_front(element);
}

void Panel::Add_Element(Panel_Element& element)
//assumes placed at back
{
	elements.push_back(element);
}
