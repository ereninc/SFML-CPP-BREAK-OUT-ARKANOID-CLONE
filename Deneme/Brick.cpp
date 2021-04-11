#include "Brick.hpp"
#include "Scene.hpp"
#include <iostream>
#include <memory>

std::string fileName3 = "";
Brick::Brick(float x, float y)
{
	m_brick.setPosition(x, y);
	Random();

	//1. yol
	/*if (m_brickTexture.loadFromFile(fileName3)) {
		m_brickSprite.setTexture(m_brickTexture);
		m_brickSprite.setScale(.35, .2);
		m_brickSprite.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
		m_brickSprite.setPosition(m_brick.getPosition());
	}*/

	//2. yol
	/*this->LoadTextures();
	this->m_brickSprite.setTexture(this->m_texmgr.GetRef(fileName3));
	m_brickSprite.setScale(.35, .2);
	m_brickSprite.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
	m_brickSprite.setPosition(m_brick.getPosition());*/
	InitBrick();
}

void Brick::InitBrick()
{
	m_brick.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_brick.setOutlineColor(sf::Color::White);
	m_brick.setOutlineThickness(2.0f);
	m_brick.setSize(sf::Vector2f(80.0f, 20.0f));
}


/*void Brick::LoadTextures()
{
	m_texmgr.LoadTextures("brickBlue", "resimler/Bricks/brick_blue_small.png");
	m_texmgr.LoadTextures("brickGreen","resimler/Bricks/brick_green_small.png");
	m_texmgr.LoadTextures("brickPink", "resimler/Bricks/brick_pink_small.png");
	m_texmgr.LoadTextures("brickViolet", "resimler/Bricks/brick_violet_small.png");
	m_texmgr.LoadTextures("brickYellow", "resimler/Bricks/brick_yellow_small.png");
}*/

void Brick::Random()
{
	srand(time(NULL));
	int b = rand() % 5 + 1;
	if (b == 1) fileName3 = "brickBlue";
	if (b == 2) fileName3 = "brickGreen";
	if (b == 3) fileName3 = "brickPink";
	if (b == 4) fileName3 = "brickViolet";
	if (b == 5) fileName3 = "brickYellow";
}

void Brick::BrickDraw(sf::RenderWindow& window)
{
	window.draw(m_brick);
	//window.draw(m_brickSprite);
}

int Brick::GetHealth()
{
	return m_health;
}

void Brick::GetDamage()
{
	m_health -= 1;
	m_brick.setFillColor(sf::Color::Black);
}

sf::RectangleShape Brick::GetBrick()
{
	return sf::RectangleShape(m_brick);
}

Brick::~Brick()
{
}