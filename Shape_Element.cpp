#include "Shape_Element.h"

Shape_Element::Shape_Element(sf::Texture& texture, Element_Properties& properties) : Panel_Element()
{
	shape.setSize(properties.size);
	shape.setOrigin(properties.origin);
	shape.setTexture(&texture);
	this->properties = properties;
}

Shape_Element::Shape_Element(sf::Color colour, Element_Properties& properties) : Panel_Element()
{
	shape.setSize(properties.size);
	shape.setOrigin(properties.origin);
	shape.setFillColor(colour);
	this->properties = properties;
}

void Shape_Element::Draw(sf::RenderWindow& window, sf::Vector2f& panel_origin)
{
	shape.setPosition(panel_origin + properties.position);
	window.draw(shape);
}

