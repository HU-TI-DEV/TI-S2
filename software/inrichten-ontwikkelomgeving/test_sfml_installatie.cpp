/// @file test_sfml_installatie.cpp -- SFML install test
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp> // for SFML version
#include <iostream>

// print SFML version
void print_SFML_version()
{
    std::cout
        << "Current SFML version: " << std::endl
        << SFML_VERSION_MAJOR << "."
        << SFML_VERSION_MINOR << "."
        << SFML_VERSION_PATCH << std::endl;
}

// currently only checking on major version number
bool issupported_SFML_version()
{
    std::cout << "This program only supports SFML 2.x.x. Your version is:" << std::endl;
    print_SFML_version();
    return (SFML_VERSION_MAJOR == 2);
}

int main()
{
    if (!issupported_SFML_version())
        return -1;
    // else
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFMLtest", sf::Style::Default, sf::ContextSettings(0, 0, 2));
    sf::RectangleShape square(sf::Vector2f(200.0, 200.0));
    sf::CircleShape circle(100.0);
    square.setPosition(sf::Vector2f(150.0, 200.0));
    circle.setPosition(sf::Vector2f(450.0, 200.0));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(square);
        window.draw(circle);
        window.display();
        sf::sleep(sf::milliseconds(20));
    }
    return 0;
}