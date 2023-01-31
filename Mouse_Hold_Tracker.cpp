#include "Mouse_Hold_Tracker.h"

void Mouse_Hold_Tracker::Update_Mouse_Position(sf::Vector2i& new_pos)
{
	new_position = new_pos;
}

sf::Vector2f Mouse_Hold_Tracker::Get_Updated_Position()
{
	return sf::Vector2f(new_position) + offset;
}
