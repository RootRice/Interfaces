#pragma once
#include <vector>
#include "Panel.h"
class GUI
{
public:
	GUI(sf::RenderWindow& window) : window(window){};

	Panel& Add_Panel(Panel::Panel_Properties& properties);
	void Remove_Panel(Panel& panel, unsigned int index_guide);
	void Draw_Panels();
private:
	sf::RenderWindow& window;

	struct Panel_Info
	{
		Panel p;
		unsigned int layer;
	};
	std::vector<Panel_Info> panels;

	void Remove_Panel(unsigned int index);
	void Update_Panel_Order(char update_amount);
};

