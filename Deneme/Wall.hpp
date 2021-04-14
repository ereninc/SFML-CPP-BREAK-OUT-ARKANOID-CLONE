#pragma once
#include <SFML/Graphics.hpp>

class Wall
{
public:
	Wall(float x = 0.0f, float y = 0.0f);
	void InitWall();
	void DrawWall(sf::RenderWindow& window);
	sf::Sprite GetWall();
	~Wall();
private:
	sf::Sprite m_wall;
	sf::Texture m_wallTexture;
};