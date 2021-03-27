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
	sf::Vector2f GetPosition();
	void ClampBorders();
	bool IsBallOutside() const;
	void CheckPlayerCollision();
	float GetBallPosX() const;
	float GetBallPosY() const;
	~Ball();
private:
	Window m_window;
	Player m_player;
	bool m_isBallOutside;
	sf::CircleShape m_ball;
	sf::Vector2f m_ballPosition;
	sf::Vector2f m_ballSpeedVec;
	float m_ballSpeed;
	bool isStarted;
};