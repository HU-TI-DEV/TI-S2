/// @file test_sfml_installatie.cpp -- SFML install test
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp> // for SFML version


/// print SFML version data
void print_SFML_version()
{
    std::cout
        << "Current SFML version: " << std::endl
        << SFML_VERSION_MAJOR << "."
        << SFML_VERSION_MINOR << "."
        << SFML_VERSION_PATCH << std::endl;
}

/// currently only checking on major version number
bool issupported_SFML_version()
{
    std::cout << "This program only supports SFML 2.x.x. and 3.0.x Your version is:" << std::endl;
    print_SFML_version();
    return (SFML_VERSION_MAJOR == 2 || SFML_VERSION_MAJOR == 3);
}

// next code works only for SFML 2.x.x. versions
#if defined(SFML_VERSION_MAJOR) && (SFML_VERSION_MAJOR == 2)
void show_window()
{
    // set up a window with title "SFML 2.x.x. window"
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML 2.x.x window");
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        window.display();
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // drawing commands go here...

        // clear the window
        window.clear();
        // show the window
        window.display();
        // prevent shivering (caused by continuous refreshing)
        sf::sleep(sf::milliseconds(20));
    }
}
#elif defined(SFML_VERSION_MAJOR) && (SFML_VERSION_MAJOR == 3)
// next code works only for SFML 3.x.x. versions
void show_window()
{
    // set up a window with title "SFML 3.x.x. window"
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.x.x window");
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        // Remainder of main loop

        // drawing commands go here...

        // clear the window
        window.clear();
        // show the window
        window.display();
        // prevent shivering (caused by continuous refreshing)
        sf::sleep(sf::milliseconds(20));
    }
}
#else
    std::cout << "Sorry, unsupported SFML version. Cannot continue." << std::endl;
    print_SFML_version();
    return;
#endif

int main()
{
    print_SFML_version(); // use when you want to check the SFML version
    show_window();        // show window based on SFML2 or SFML3 version
    return 0;
}