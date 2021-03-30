#pragma once
#include <SFML/Graphics.hpp>

class Brick 
{
public:
	Brick();
	void InitBrick();
	void BrickDraw(sf::RenderWindow& window);
	sf::RectangleShape GetBrick();
	~Brick();
private:
	sf::RectangleShape m_brick;
};