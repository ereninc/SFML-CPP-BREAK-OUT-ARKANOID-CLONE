#include "Button.hpp"

Button::Button()
{
}

void Button::Text(sf::String text)
{
	m_text.setString(text);
	auto textSize = m_text.getLocalBounds();
	float x = abs(textSize.left);
	float y = textSize.top;

	float width = textSize.width + x * 2 + 20;
	float height = textSize.height + y * 2;
	Size(width, height);
	m_text.setPosition(m_backGround.getPosition().x + x + 10, 0);
}

void Button::Color(sf::Color color)
{
	m_backGround.setFillColor(color);
}

void Button::Font(sf::Font& font)
{
	m_text.setFont(font);
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(m_backGround);
	window.draw(m_text);
}

void Button::Size(float width, float height)
{
	m_backGround.setSize(sf::Vector2f(width, height));
}

void Button::Position(float x, float y)
{
	auto textSize = m_text.getLocalBounds();
	float textX = abs(textSize.left);
	float textY = textSize.top;
	m_text.setPosition(x + textX + 10, y);

	m_backGround.setPosition(sf::Vector2f(x, y));
}
