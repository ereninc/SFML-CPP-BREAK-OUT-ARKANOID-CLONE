#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include "Window.hpp"

int main()
{
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Magenta);
	shape.setOutlineThickness(5.0f);
	shape.setOutlineColor(sf::Color::White);


	GameManager gameManager;
	while (!gameManager.isFinished())
	{
		gameManager.InputControl();
		gameManager.UpdateScene();
		gameManager.DrawScene();
		gameManager.RestartClock();
	}

	/*Window window;
	while (!window.isClosed())
	{
		window.EventControl();
		window.StartDrawing();
		window.Draw(shape);
		window.EndDrawing();
	}*/

	return 0;
}