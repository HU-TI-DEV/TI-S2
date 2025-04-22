// SFML 2.5.1 version
#include <SFML/Graphics.hpp>
#include <cmath>

const float PI = 3.14159265f;

class Wiel
{
private:
	sf::RenderWindow& renderWindow;
	sf::CircleShape circle;
	sf::Vector2f position;

public:
	Wiel(int x, int y, int radius, sf::RenderWindow& renderWindow)
		:position((float)x, (float)y), circle((float)radius), renderWindow(renderWindow)
	{
		// set inside color of Wiel to yellow
		circle.setFillColor(sf::Color::Yellow);
		// set the origin of the circle from the top left corner to its center
		circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
	}

	void setPos(int xNew, int yNew) {
		position = { (float)xNew, (float)yNew };
	}

	void draw() {
		// set the position of the SFML-object (setPos might have changed the coordinates)
		circle.setPosition(position);
		renderWindow.draw(circle);
	}
};

// TODO: add Chassis.

class Auto {

private:
	Wiel voorwiel, achterwiel;
	int x, y;
	const int voorwielX = 140;
	const int voorwielY = 35;
	const int achterwielX = 40;
	const int achterwielY = 35;

public:
	Auto(int x, int y, sf::RenderWindow& renderWindow)
		: voorwiel(0, 0, 10, renderWindow),
		achterwiel(0, 0, 10, renderWindow),
		x(x), y(y)
	{}

	void setPos(int x, int y)
	{
		this->x = x;
		this->y = y;

		voorwiel.setPos(
			this->x + voorwielX,
			this->y + voorwielY);

		achterwiel.setPos(
			this->x + achterwielX,
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
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Auto Class");

	Auto clownsAuto(100, 500, window);

	sf::Clock clock;

	// main event loop: run the program as long as the window is open
	while (window.isOpen()) {

		// check all the window's events received since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		} // while event

		window.clear(sf::Color::Black);

		// compute new position
		float t = clock.getElapsedTime().asSeconds();
		float horizontalOffset = 100.f * std::sin(2 * PI * t);
		clownsAuto.setPos(100 + (int(horizontalOffset)), 500);

		clownsAuto.draw();

		window.display();
	}// while window.isOpen()

	return 0;
}
