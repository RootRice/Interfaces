#pragma once
#include <vector>
#include "Panel.h"
class GUI
{
public:
	GUI();

	void Add_Panel(sf::RenderWindow& window, sf::Vector2u size);
	void Remove_Panel(Panel& panel, unsigned int index_guide);
	void Draw_Panels();
private:
	struct panel_info
	{
		Panel p;
		unsigned int layer;
	};
	std::vector<panel_info> panels;

	void Remove_Panel(unsigned int index);
	void Update_Panel_Order(char update_amount);
};

