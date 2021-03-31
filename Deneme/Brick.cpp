#include "Brick.hpp"
#include "Scene.hpp"

Brick::Brick()
{
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
	float xOffset = 20.0f;
	float yOffset = 0.0f;
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			window.draw(m_brick);
			m_brick.setPosition(sf::Vector2f(0.0f, 0.0f));
			auto brickPos = m_brick.getPosition();
			m_brick.setPosition(brickPos.x + 20 * 6 * x, brickPos.y + 40 * y);
		}
	}
}

sf::RectangleShape Brick::GetBrick()
{
	return sf::RectangleShape(m_brick);
}

Brick::~Brick()
{
}
