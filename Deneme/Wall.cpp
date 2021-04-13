#include "Wall.hpp"
#include <iostream>
#include "TextureManager.hpp"

TextureManager texture;
sf::Texture wallTexture;

Wall::Wall(float x, float y)
{
	m_wall.setPosition(x, y);
	texture.RandomWall();
	texture.ImportTextures();
	wallTexture = texture.GetWall();
	InitWall();
}

void Wall::InitWall()
{
	/*m_wall.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_wall.setSize(sf::Vector2f(20.0f, 20.0f));*/
	m_wall.setTexture(wallTexture);
	m_wall.setScale(.11, .11);
	m_wall.setTextureRect(sf::IntRect(45.0f, 45.0f, 177.0f, 177.0f));
	
}

void Wall::DrawWall(sf::RenderWindow& window)
{
	window.draw(m_wall);
}

sf::Sprite Wall::GetWall()
{
	return sf::Sprite(m_wall);
}

Wall::~Wall()
{
}
