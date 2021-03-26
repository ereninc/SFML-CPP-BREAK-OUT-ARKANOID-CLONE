#include "Ball.hpp"

Ball::Ball()
{
}

void Ball::SetBall()
{
	m_ball.setFillColor(sf::Color::Red);
	m_ball.setRadius(10.0f);
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	auto ballPos = GetPosisiton();
	auto screenSize = window.getSize();
	if (isStarted)
	{
		m_ballSpeed += 0.1f;
		window.draw(m_ball);
		if (ballPos.x >= 0 && ballPos.y >= 0 && ballPos.x <= screenSize.x && ballPos.y <= screenSize.y)
		{
			m_ball.setPosition(sf::Vector2f(400.0f - m_ballSpeed, 540.0f - m_ballSpeed));
		}
		/*if (ballPos.x <= 0)
		{
			m_ballPosition *= -1.0f;
		}*/
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
