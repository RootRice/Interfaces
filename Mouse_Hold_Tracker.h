#pragma once
#include <SFML/Graphics.hpp>
class Mouse_Hold_Tracker
{
public:
	Mouse_Hold_Tracker(sf::Vector2i& original_position, sf::Vector2f& offset) : original_position(original_position), offset(offset) {};

	void Update_Mouse_Position(sf::Vector2i& new_pos);

	sf::Vector2f Get_Updated_Position();

private:
	sf::Vector2i original_position;
	sf::Vector2f offset;
	sf::Vector2i new_position;
};

