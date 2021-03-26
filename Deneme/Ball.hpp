#pragma once
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Ball 
{
public:
	Ball();
	void SetBall();
	void DrawBall(sf::RenderWindow& window);
	void MovementControl();
	sf::Vector2f GetPosisiton();
	~Ball();
private:
	Window m_window;
	sf::CircleShape m_ball;
	sf::Vector2f m_ballPosition;
	sf::Vector2f m_ballSpeedVec;
	float m_ballSpeed = 1.0f;
	bool isStarted = false;
};