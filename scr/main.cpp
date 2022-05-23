#include <SFML/Graphics.hpp>
#include <iostream>
#include "../includes/Defender.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!",sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Defender defender1 = Defender(1);
    Defender defender2 = Defender(2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2 mouse_pos = sf::Mouse::getPosition(window);
        shape.setPosition(mouse_pos.x - shape.getRadius(), mouse_pos.y - shape.getRadius());

        window.clear();
        window.draw(shape);
        window.draw(defender1);
        window.draw(defender2);
        window.display();
    }

    return 0;
}