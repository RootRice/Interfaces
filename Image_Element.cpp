#include "Image_Element.h"

Image_Element::Image_Element(sf::Texture& texture, sf::Vector2f& position)
{
	properties.position = position;
	properties.size = sf::Vector2f(texture.getSize());
	properties.origin = sf::Vector2f(properties.size * 0.5f);

	image.setTexture(texture);
	image.setOrigin(properties.origin);
}

void Image_Element::Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin)
{
	image.setPosition(panel_origin + properties.position);
	window.draw(image);
}

void Image_Element::Take_Input(sf::Vector2u& mouse_pos, sf::Event& button_presses)
{
}
