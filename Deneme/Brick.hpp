#pragma once
#include <SFML/Graphics.hpp>

class Brick 
{
public:
	Brick(float x = 0.0f, float y = 0.0f);
	void InitBrick();
	void Random();
	void BrickDraw(sf::RenderWindow& window);
	sf::RectangleShape GetBrick();
	~Brick();
private:
	sf::RectangleShape m_brick;
	sf::Texture m_brickTexture;
	sf::Sprite m_brickSprite;
};