#pragma once
#include <SFML/Graphics.hpp>

class Ball 
{
public:
	Ball();
	void SetBall();
	void DrawBall(sf::RenderWindow& window);
private:
	sf::CircleShape m_ball;
};