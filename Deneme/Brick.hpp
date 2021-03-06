#pragma once
#include <SFML/Graphics.hpp>

class Brick
{
public:
	Brick(float x = 0.0f, float y = 0.0f);
	void InitBrick();
	void BrickDraw(sf::RenderWindow& window);
	int GetHealth();
	void GetDamage();
	sf::Sprite GetBrick();
	~Brick();
private:
	int m_health = 2;
	sf::Sprite m_brick;
	sf::Texture m_brickTexture;
	sf::Sprite m_brickSprite;
};