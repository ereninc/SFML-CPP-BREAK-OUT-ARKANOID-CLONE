#pragma once
#include <SFML/Graphics.hpp>
#include "WindowInterface.hpp"

class Button: public WindowInterface
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
	sf::Vector2f GetSize();
private:
	sf::RectangleShape m_backGround;
	sf::Text m_text;
	sf::Vector2f m_size;
	sf::Vector2f m_position;

	// Inherited via WindowInterface
	virtual void MouseMove(int x, int y) override;
	virtual void MouseOnEnable(sf::Event::MouseButtonEvent btnEvent) override;
	virtual void MouseOnDisable(sf::Event::MouseButtonEvent btnEvent) override;
	virtual bool isOn(int x, int y) override;

	// Inherited via WindowInterface
	virtual void isNotOn() override;
};