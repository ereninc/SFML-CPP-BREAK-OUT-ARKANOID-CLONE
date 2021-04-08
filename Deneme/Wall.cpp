#include "Wall.hpp"
#include <iostream>

std::string fileName4 = "";
Wall::Wall(float x, float y)
{
	m_wall.setPosition(x, y);
	/*Random();
	if (m_wallTexture.loadFromFile(fileName4)) {
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

void Wall::Random()
{
	srand(time(NULL));
	int a = rand() % 6 + 1;
	std::cout << "Ball rnd : " << a << std::endl;
	if (a == 1) fileName4 = "resimler/brick.png";
	if (a == 2) fileName4 = "resimler/brick_blue.png";
	if (a == 3) fileName4 = "resimler/brick_pink_side.png";
	if (a == 4) fileName4 = "resimler/brick_red.png";
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
