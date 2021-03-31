#include "Brick.hpp"
#include "Scene.hpp"

Brick::Brick(float x, float y)
{
	m_brick.setPosition(x, y);
	InitBrick();
}

void Brick::InitBrick()
{
	m_brick.setFillColor(sf::Color::Cyan);
	m_brick.setOutlineColor(sf::Color::White);
	m_brick.setOutlineThickness(2.0f);
	m_brick.setSize(sf::Vector2f(80.0f, 20.0f));
}

void Brick::BrickDraw(sf::RenderWindow& window)
{
	window.draw(m_brick);
}

sf::RectangleShape Brick::GetBrick()
{
	return sf::RectangleShape(m_brick);
}

Brick::~Brick()
{
}