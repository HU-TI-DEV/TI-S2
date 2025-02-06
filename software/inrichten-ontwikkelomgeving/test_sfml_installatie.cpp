/// @file main.c -- SFML install test
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main ()
{
    sf::RenderWindow window (sf::VideoMode(800,600), "SFMLtest", sf::Style::Default, sf::ContextSettings(0, 0, 2));
    sf::RectangleShape square(sf:Vector2f(200.0,200.0));
    sf::CircleShape circle(200.0);
    square.setPosition(sf:Vector2f(300.0,200.0));
    circle.setPosition(sf:Vector2f(300.0,200.0));
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(square);
        window.draw(circle);
        window.display ();
        sf::sleep(sf::milliseconds(20));
    }
    return 0;
}
