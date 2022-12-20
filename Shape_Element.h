#pragma once
#include "Panel_Element.h"
class Shape_Element :
    public Panel_Element
{
public:
    Shape_Element(sf::Texture& texture, Element_Properties& properties);
    Shape_Element(sf::Color& texture, Element_Properties& properties);

    void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) override;
    void Take_Input(sf::Vector2u& mouse_pos, sf::Event& button_presses) override;
private:
    sf::RectangleShape shape;
};

