#pragma once
#include <SFML/Graphics.hpp>

class Brick 
{
public:
	Brick();
	void InstantiateBricks();
	void BrickDraw(sf::RenderWindow& window);
	sf::RectangleShape GetBrick();
	~Brick();
private:
	sf::RectangleShape m_brick;
};