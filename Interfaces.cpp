#include <iostream>
#include <SFML/Graphics.hpp>
#include "Panel.h"
#include "Shape_Element.h"
#include "GUI.h"

int main()
{
    sf::RenderWindow my_window(sf::VideoMode(600, 600), "Interfaces!");
    GUI my_gui(my_window);

    Panel::Panel_Properties panel_props{ sf::Vector2f(200, 300), Panel::anchor_point::center };
    Panel& panel_to_edit = my_gui.Add_Panel(panel_props);
    Panel_Element::Element_Properties element_props{ sf::Vector2f(50, 50), sf::Vector2f(25, 25), sf::Vector2f(0,0) };
    Shape_Element element(sf::Color::Red, element_props);
    panel_to_edit.Add_Element(element);

    while (my_window.isOpen())
    {
        my_window.clear();
        my_gui.Draw_Panels();
        my_window.display();
    }
    
}
