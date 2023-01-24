#pragma once
#include "Panel_Element.h"
class Image_Element :
    public Panel_Element
{
public:
    Image_Element(sf::Texture& texture, sf::Vector2f& position);

    void Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin) override;

private:
    sf::Sprite image;
    sf::Vector2i position;
};

