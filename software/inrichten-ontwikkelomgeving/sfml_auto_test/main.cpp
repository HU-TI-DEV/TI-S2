#include <SFML/Graphics.hpp>
#include <cmath>

const float PI = 3.14159265f;
class Wiel
{
    private:
        int x,y;
        sf::RenderWindow & renderWindow;
        sf::CircleShape circle;

    public:
        Wiel(int x, int y, int radius, sf::RenderWindow & renderWindow)
        :x(x),y(y),renderWindow(renderWindow),circle(radius)
        { 
            circle.setFillColor(sf::Color::Yellow);
            circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
        }

        void setPos(int xNew, int yNew)
        {
            x = xNew;
            y = yNew;
        }

        void draw()
        {
            circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
            renderWindow.draw(circle);
        }
};

// TODO: add Chassis.

class Auto
{
    private:
        Wiel voorwiel, achterwiel;
        int x, y;
        const int voorwielX = 140;
        const int voorwielY = 35;
        const int achterwielX = 40;
        const int achterwielY = 35;

    public:
        Auto(int x, int y, sf::RenderWindow& renderWindow)
        : voorwiel(0,0,10,renderWindow),
        achterwiel(0,0,10,renderWindow),
        x(x), y(y)
        {
            setPos(x,y);
        }

    void setPos(int x, int y)
    {
        this->x = x;
        this->y = y;

        voorwiel.setPos(this->x + voorwielX,
                        this->y + voorwielY);

        achterwiel.setPos(this->x + achterwielX,
                          this->y + achterwielY);
    }

    void draw()
    {
        voorwiel.draw();
        achterwiel.draw();
    }
};

int main()
{
    // Maak een venster van 800x600 met de titel "Hello SFML"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");

    Auto clownsAuto(100,500,window);
    sf::Clock clock;

    // Hoofdlus: blijf het venster tonen totdat deze gesloten wordt
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Sluit het venster als er op de sluitknop wordt geklikt
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Maak het venster zwart en toon de inhoud
        window.clear(sf::Color::Black);

        float t = clock.getElapsedTime().asSeconds();
        float horizontalOffset = 100.f * std::sin(2 * PI * t);
        clownsAuto.setPos(100+(int(horizontalOffset)),500);

        clownsAuto.draw();

        window.display();
    }
    
    return 0;
}
