#pragma once
#include "Panel_Element.h"
class Image_Element :
    public Panel_Element
{
public:
    Image_Element(sf::Texture& texture, sf::Vector2f& position);

    void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) override;
    void Take_Input(sf::Vector2u& mouse_pos, sf::Event& button_presses) override;

private:
    sf::Sprite image;
    sf::Vector2i position;
};

