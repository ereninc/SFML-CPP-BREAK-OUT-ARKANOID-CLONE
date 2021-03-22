#include "Button.hpp"
#include <iostream>

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

void Button::OutlineColor(sf::Color outlineColor)
{
	m_backGround.setOutlineThickness(2.0f);
	m_backGround.setOutlineColor(outlineColor);
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
	if (m_text.getLocalBounds().width < width)
	{
		m_size = sf::Vector2f(width, height);
		m_backGround.setSize(m_size);
	}
}

void Button::Position(float x, float y)
{
	m_position = sf::Vector2f(x, y);
	auto textSize = m_text.getLocalBounds();
	float textX = abs(textSize.left);
	float deltaX = (m_size.x - textSize.width) / 2.0f;
	m_text.setPosition(x + textX + deltaX, y);
	m_backGround.setPosition(m_position);
}

sf::Vector2f Button::GetSize()
{
	return m_size;
	return sf::Vector2f();
}

void Button::MouseMove(int x, int y)
{
	std::cout << x << " , " << y << std::endl;
	m_backGround.setFillColor(sf::Color::Cyan);
}

void Button::MouseOnEnable(sf::Event::MouseButtonEvent btnEvent)
{
	WindowInterface::MouseOnEnable(btnEvent);
	m_backGround.setFillColor(sf::Color::Cyan);
	std::cout << "Clicked!" << std::endl;
}

void Button::MouseOnDisable(sf::Event::MouseButtonEvent btnEvent)
{
	//std::cout << "Click stopped!" << std::endl;
	isNotOn();
}

bool Button::isOn(int x, int y)
{
	auto pos = m_backGround.getPosition();
	auto size = m_backGround.getSize();
	if (pos.x <= x && pos.x + size.x >= x && pos.y <= y && pos.y + size.y >= y)
	{
		return true;
	}
	return false;
}

void Button::isNotOn()
{
	m_backGround.setFillColor(sf::Color::Magenta);
}
