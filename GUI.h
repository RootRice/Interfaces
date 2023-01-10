#pragma once
#include <list>
#include "Panel.h"
class GUI
{
public:
	GUI(sf::RenderWindow& window) : window(window){};

	Panel& Add_Panel(Panel::Panel_Properties& properties);
	void Remove_Panel(Panel& panel);
	void Draw_Panels();
	void Take_Input(sf::Event e, sf::Vector2f mouse_pos);
private:
	sf::RenderWindow& window;

	
	std::list<Panel> panels;

	void Remove_Panel(unsigned int index);
};

