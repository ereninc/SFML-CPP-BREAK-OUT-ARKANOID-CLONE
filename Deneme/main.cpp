#include <SFML/Graphics.hpp>
#include "Window.hpp"

int _width = 800;
int _height = 600;
float x = 0;
int _speed = 100;

int main()
{
	Window window;

	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Magenta);
	shape.setOutlineThickness(5.0f);
	shape.setOutlineColor(sf::Color::White);

	sf::Clock clock;
	while (!window.isClosed())
	{
		window.EventControl();
		
		window.StartDrawing();
		window.Draw(shape);
		window.EndDrawing();
	}
	return 0;
}