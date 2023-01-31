#include "GUI.h"

Panel& GUI::Add_Panel(Panel::Panel_Properties& properties)
{
	const int panel_count = panels.size();
	panels.push_back(Panel(properties, window));
	
	return *--panels.end();
}

void GUI::Remove_Panel(Panel& panel)
{
	std::list<Panel>::iterator it;
	std::list<Panel>::iterator end = panels.end();
	for (it = panels.begin(); it != end; ++it)
	{
		if (&panel == &*it)
		{
			panels.erase(it);
			break;
		}
	}
}

void GUI::Draw_Panels()
{
	std::list<Panel>::reverse_iterator it;
	std::list<Panel>::reverse_iterator end = panels.rend();
	for (it = panels.rbegin(); it != end; ++it)
	{
		it->Draw();
	}

	int x = 0;
}

void GUI::Take_Input(sf::Event e, sf::Vector2f mouse_pos)
{
		std::list<Panel>::iterator it;
		std::list<Panel>::iterator start = panels.begin();
		std::list<Panel>::iterator end = panels.end();
		for (it = start; it != end; ++it)
		{
			
				it->Take_Input(mouse_pos, e);
				if(e.type == sf::Event::MouseButtonPressed & it->Check_Within_Bounds(mouse_pos))
					panels.splice(start, panels, it);
			
		}
}

void GUI::Remove_Panel(unsigned int index)
{
	std::list<Panel>::iterator it = panels.begin();
	
	for (int i = 0; i < index; i++)
	{
		it++;
	}
	panels.erase(it);
}
