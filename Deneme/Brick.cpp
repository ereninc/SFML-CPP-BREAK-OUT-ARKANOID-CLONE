#include "Brick.hpp"
#include "Scene.hpp"
#include <iostream>

std::string fileName3 = "";
Brick::Brick(float x, float y)
{
	m_brick.setPosition(x, y);
	/*Random();
	if (!m_brickTexture.loadFromFile(fileName3))
		std::cout << "PNG YOK" << std::endl;
	else {
		m_brickSprite.setTexture(m_brickTexture);
		m_brickSprite.setScale(.35, .2);
		m_brickSprite.setTextureRect(sf::IntRect(140.0f, 178.0f, 234.0f, 104.0f));
		m_brickSprite.setPosition(m_brick.getPosition());
	}*/
	InitBrick();
}

void Brick::InitBrick()
{
	m_brick.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	m_brick.setOutlineColor(sf::Color::White);
	m_brick.setOutlineThickness(2.0f);
	m_brick.setSize(sf::Vector2f(80.0f, 20.0f));
}

void Brick::Random()
{
	srand(time(NULL));
	int b = rand() % 5 + 1;
	std::cout << "Brick rnd : " << b << std::endl;
	if (b == 1) fileName3 = "brick_blue_small.png";
	if (b == 2) fileName3 = "brick_green_small.png";
	if (b == 3) fileName3 = "brick_ping_small.png";
	if (b == 4) fileName3 = "brick_violet_small.png";
	if (b == 5) fileName3 = "brick_yellow_small.png";
}

void Brick::BrickDraw(sf::RenderWindow& window)
{
	window.draw(m_brick);
	//window.draw(m_brickSprite);
	//m_brickSprite.setPosition(m_brick.getPosition());
}

sf::RectangleShape Brick::GetBrick()
{
	return sf::RectangleShape(m_brick);
}

Brick::~Brick()
{
}