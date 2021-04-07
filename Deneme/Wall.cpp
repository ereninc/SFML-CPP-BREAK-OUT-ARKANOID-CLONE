#include "Wall.hpp"
#include <iostream>

Wall::Wall(float x, float y)
{
	m_wall.setPosition(x, y);
	/*if (!m_wallTexture.loadFromFile("brick.png"))
		std::cout << "PNG YOK" << std::endl;
	else {
		m_wallSprite.setTexture(m_wallTexture);
		m_wallSprite.setScale(.11, .11);
		m_wallSprite.setTextureRect(sf::IntRect(40.0f, 45.0f, 174.0f, 180.0f));
		m_wallSprite.setPosition(m_wall.getPosition());
	}*/
	InitWall();
}

void Wall::InitWall()
{
	srand(time(NULL));
	m_wall.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_wall.setSize(sf::Vector2f(20.0f, 20.0f));
}

void Wall::DrawWall(sf::RenderWindow& window)
{
	window.draw(m_wall);
	//window.draw(m_wallSprite);
}

sf::RectangleShape Wall::GetWall()
{
	return sf::RectangleShape(m_wall);
}

Wall::~Wall()
{
}
