#include "Ball.hpp"
#include <iostream>

Ball::Ball()
{
}

void Ball::SetBall()
{
	m_ball.setFillColor(sf::Color::Red);
	m_ball.setRadius(10.0f);
	m_ballSpeedVec = {1.0f, 1.0f};
	m_ball.setPosition(sf::Vector2f(400.0f, 540.0f));
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	auto ballPos = GetPosisiton();
	auto screenSize = window.getSize();
	if (isStarted)
	{
		m_ballSpeedVec.x += 0.001f;
		m_ballSpeedVec.y += 0.001f;
		window.draw(m_ball); 
		m_ball.setPosition(ballPos.x - m_ballSpeedVec.x, ballPos.y - m_ballSpeedVec.y);
		std::cout << ballPos.x << ", " << ballPos.y << std::endl;
		if (ballPos.x <= 0)
		{
			m_ballSpeedVec.x = -abs(m_ballSpeedVec.x);
		}
		if (ballPos.x >= screenSize.x)
		{
			m_ballSpeedVec.x = abs(m_ballSpeedVec.x);
		}
		if (ballPos.y <= 0)
		{
			m_ballSpeedVec.y = -abs(m_ballSpeedVec.y);
		}
		if (ballPos.y >= screenSize.y)
		{
			m_ballSpeedVec.y = abs(m_ballSpeedVec.y); //gameover
		}
	}
}

void Ball::MovementControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) isStarted = true;
}

sf::Vector2f Ball::GetPosisiton()
{
	m_ballPosition = m_ball.getPosition();
	return sf::Vector2f(m_ballPosition);
}

Ball::~Ball()
{
}
