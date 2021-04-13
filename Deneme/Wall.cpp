#include "Wall.hpp"
#include <iostream>

std::string fileName4 = "";
Wall::Wall(float x, float y)
{
	m_wall.setPosition(x, y);
	Random();

	//1. yol
	/*if (m_wallTexture.loadFromFile(fileName4)) {
		m_wallSprite.setTexture(m_wallTexture);
		m_wallSprite.setScale(.11, .11);
		m_wallSprite.setTextureRect(sf::IntRect(40.0f, 45.0f, 174.0f, 180.0f));
		m_wallSprite.setPosition(m_wall.getPosition());
	}*/

	//2. yol
	/*this->LoadTextures();
	this->m_wallSprite.setTexture(this->m_texmgr.GetRef(fileName4));
	m_wallSprite.setScale(.12, .12);
	m_wallSprite.setTextureRect(sf::IntRect(40.0f, 45.0f, 174.0f, 180.0f));
	m_wallSprite.setPosition(m_wall.getPosition());*/
	InitWall();
}

void Wall::InitWall()
{
	m_wall.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_wall.setSize(sf::Vector2f(20.0f, 20.0f));
}

void Wall::LoadTextures()
{
	/*m_texmgr.LoadTextures("wallGreen", "resimler/brick.png");
	m_texmgr.LoadTextures("wallBlue", "resimler/brick_blue.png");
	m_texmgr.LoadTextures("wallPink", "resimler/brick_pink_side.png");
	m_texmgr.LoadTextures("wallRed", "resimler/brick_red.png");*/
}

void Wall::Random()
{
	int a = rand() % 6 + 1;
	if (a == 1) fileName4 = "wallGreen";
	if (a == 2) fileName4 = "wallBlue";
	if (a == 3) fileName4 = "wallPink";
	if (a == 4) fileName4 = "wallRed";
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
