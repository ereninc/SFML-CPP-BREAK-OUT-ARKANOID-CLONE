#pragma once
#include<SFML/Graphics.hpp>

class Window
{
public:
	Window();
	void SetWindow(unsigned int width, unsigned int height, sf::String title);
	void StartDrawing();
	void EndDrawing();
	bool isClosed();
	void EventControl();
	void Draw(sf::Drawable& shape);
	sf::RenderWindow m_sfmlWindow;
	sf::RenderWindow& getWindow();
};