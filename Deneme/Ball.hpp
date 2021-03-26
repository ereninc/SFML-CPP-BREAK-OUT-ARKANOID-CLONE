#pragma once
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Player.hpp"

class Ball 
{
public:
	Ball();
	void SetBall();
	void DrawBall(sf::RenderWindow& window);
	void MovementControl();
	sf::Vector2f GetPosisiton();
	void ClampBorders();
	bool IsBallOutside();
	float GetBallPosX();
	float GetBallPosY();
	~Ball();
private:
	Window m_window;
	Player m_player;
	bool m_isBallOutside = false;
	sf::CircleShape m_ball;
	sf::Vector2f m_ballPosition;
	sf::Vector2f m_ballSpeedVec;
	float m_ballSpeed = 0.0001f;
	bool isStarted = false;
};