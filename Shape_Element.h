#pragma once
#include "Panel_Element.h"
class Shape_Element :
    public Panel_Element
{
public:
    Shape_Element(sf::Texture& texture, Element_Properties& properties);
    Shape_Element(sf::Color colour, Element_Properties& properties);

    void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) override;
private:
    sf::RectangleShape shape;
};

