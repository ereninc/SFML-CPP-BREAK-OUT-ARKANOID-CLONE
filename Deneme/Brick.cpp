#include "Brick.hpp"
#include "Scene.hpp"
#include <iostream>
#include <memory>
#include "TextureManager.hpp"

std::string fileName3 = "";
TextureManager tex;
sf::Texture brickTexture;
sf::Texture brickDamagedTexture;
Brick::Brick(float x, float y)
{
	//tex.Random();
	tex.ImportTextures();
	brickTexture = tex.GetRandomBrickTexture();
	m_brick.setPosition(x, y);
	//Random();
	//2. yol
	/*this->LoadTextures();
	this->m_brickSprite.setTexture(this->m_texmgr.GetRef(fileName3));
	m_brick.setScale(.35, .2);
	m_brick.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
	m_brick.setPosition(m_brick.getPosition());*/
	InitBrick();
}

void Brick::InitBrick()
{
	/*m_brick.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_brick.setOutlineColor(sf::Color::White);
	m_brick.setOutlineThickness(2.0f);
	m_brick.setSize(sf::Vector2f(80.0f, 20.0f));*/
	m_brick.setTexture(brickTexture);
	m_brick.setScale(.35, .2);
	m_brick.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
}

/*void Brick::LoadTextures()
{
	m_texmgr.LoadTextures("brickBlue", "resimler/Bricks/brick_blue_small.png");
	m_texmgr.LoadTextures("brickGreen","resimler/Bricks/brick_green_small.png");
	m_texmgr.LoadTextures("brickPink", "resimler/Bricks/brick_pink_small.png");
	m_texmgr.LoadTextures("brickViolet", "resimler/Bricks/brick_violet_small.png");
	m_texmgr.LoadTextures("brickYellow", "resimler/Bricks/brick_yellow_small.png");
}*/

/*void Brick::Random()
{
	srand(time(NULL));
	int b = rand() % 5 + 1;
	if (b == 1) fileName3 = "brickBlue";
	if (b == 2) fileName3 = "brickGreen";
	if (b == 3) fileName3 = "brickPink";
	if (b == 4) fileName3 = "brickViolet";
	if (b == 5) fileName3 = "brickYellow";
}*/

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
	//m_brick.setFillColor(sf::Color::Black);
	
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