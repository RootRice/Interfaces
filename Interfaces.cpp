#include <iostream>
#include <SFML/Graphics.hpp>
#include "Panel.h"
#include "Shape_Element.h"
#include "GUI.h"

int main()
{
    sf::RenderWindow my_window(sf::VideoMode(600, 600), "Interfaces!");
    GUI my_gui(my_window);

    //
    Panel::Panel_Properties panel_props{ sf::Vector2f(200, 150), sf::Vector2f(50, 50), Panel::anchor_point::center };
    Panel* panel_to_edit = &my_gui.Add_Panel(panel_props);
    Panel_Element::Element_Properties element_props{ sf::Vector2f(50, 50), sf::Vector2f(0, 0), sf::Vector2f(0, 0) };
    Shape_Element element(sf::Color::Red, element_props);
    panel_to_edit->Add_Element(element);
    //
    panel_props.anchor = Panel::anchor_point::top_left;
    panel_props.position = sf::Vector2f(525, 425);
    panel_props.moveable = true;
    panel_to_edit = &my_gui.Add_Panel(panel_props);
    element_props.size = sf::Vector2f(50, 50);
    element_props.origin = sf::Vector2f(0, 0);
    element_props.position = sf::Vector2f(0, 0);
    element = Shape_Element(sf::Color::Green, element_props);
    panel_to_edit->Add_Element(element, false);
    //
    panel_to_edit = NULL; delete panel_to_edit;

    while (my_window.isOpen())
    {
        my_window.clear();
        sf::Event e;
        while (my_window.pollEvent(e))
        {
            const sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(my_window));
            if (e.type == sf::Event::Closed)
                my_window.close();
            my_gui.Take_Input(e, mouse_pos);
        }
        my_gui.Draw_Panels();
        my_window.display();
    }

    //NEXT UP: HANDLE INPUTS
    
}
