#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button();
	void Text(sf::String text);
	void Color(sf::Color color);
	void OutlineColor(sf::Color outlineColor);
	void Font(sf::Font& font);
	void Draw(sf::RenderWindow& window);
	void Size(float width, float height);
	void Position(float x, float y);
private:
	sf::RectangleShape m_backGround;
	sf::Text m_text;
};