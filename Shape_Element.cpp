#include "Shape_Element.h"

Shape_Element::Shape_Element(sf::Texture& texture, Element_Properties& properties)
{
	shape.setSize(properties.size);
	shape.setOrigin(properties.origin);
	shape.setTexture(&texture);
	this->properties = properties;
}

Shape_Element::Shape_Element(sf::Color& colour, Element_Properties& properties)
{
	shape.setSize(properties.size);
	shape.setOrigin(properties.origin);
	shape.setFillColor(colour);
	this->properties = properties;
}
