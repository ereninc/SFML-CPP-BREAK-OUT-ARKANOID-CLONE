#pragma once
#include <SFML/Graphics.hpp>

class Brick 
{
public:
	Brick(float x = 0.0f, float y = 0.0f);
	void InitBrick();
	void BrickDraw(sf::RenderWindow& window);
	sf::RectangleShape GetBrick();
	~Brick();
private:
	sf::RectangleShape m_brick;
};