#include "Wall.hpp"
#include <iostream>

std::string fileName4 = "";
Wall::Wall(float x, float y)
{
	m_wall.setPosition(x, y);
	InitWall();
}

void Wall::InitWall()
{
	m_wall.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_wall.setSize(sf::Vector2f(20.0f, 20.0f));
}

void Wall::DrawWall(sf::RenderWindow& window)
{
	window.draw(m_wall);
}

sf::RectangleShape Wall::GetWall()
{
	return sf::RectangleShape(m_wall);
}

Wall::~Wall()
{
}
