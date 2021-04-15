#include "Brick.hpp"
#include "Scene.hpp"
#include <iostream>
#include "TextureManager.hpp"

TextureManager *tex = new TextureManager();
sf::Texture brickTexture;
sf::Texture brickDamagedTexture;

Brick::Brick(float x, float y)
{
	tex->ImportBrickTextures();
	brickTexture = tex->GetRandomBrickTexture();
	brickDamagedTexture = tex->GetDamagedBrickTexture();
	m_brick.setPosition(x, y);
	InitBrick();
}

void Brick::InitBrick()
{
	m_brick.setTexture(brickTexture);
	m_brick.setScale(.35, .2);
	m_brick.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
}

void Brick::BrickDraw(sf::RenderWindow& window)
{
	window.draw(m_brick);
}

int Brick::GetHealth()
{
	return m_health;
}

//Texture change and -1 health
void Brick::GetDamage()
{
	m_health -= 1;
	m_brick.setTexture(brickDamagedTexture);
	m_brick.setScale(.35, .2);
	m_brick.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
}

sf::Sprite Brick::GetBrick()
{
	return sf::Sprite(m_brick);
}

Brick::~Brick()
{
}