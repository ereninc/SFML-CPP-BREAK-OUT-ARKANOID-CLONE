#pragma once
#include <SFML/Graphics.hpp>

class Brick 
{
public:
	Brick();
	void InstantiateBricks();
	void BrickDraw(sf::RenderWindow& window);
	~Brick();
private:
	sf::RectangleShape m_brick;
};