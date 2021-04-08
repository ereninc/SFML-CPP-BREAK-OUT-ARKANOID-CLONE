#pragma once
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Player.hpp"

class Ball 
{
public:
	Ball();
	void SetBall();
	void Random();
	void DrawBall(sf::RenderWindow& window);
	void MovementControl();
	sf::Sprite GetBall();
	void ClampBorders();
	bool IsBallOutside() const;
	sf::Vector2f m_ballSpeedVec;
	~Ball();
private:
	Window m_window;
	bool m_isBallOutside;
	sf::Texture m_ballTexture;
	sf::Sprite m_ballSprite;
	sf::Vector2f m_ballPosition;
	float m_ballSpeed;
	bool isStarted;
};