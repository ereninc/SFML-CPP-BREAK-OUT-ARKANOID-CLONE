#include "Ball.hpp"
#include <iostream>

Ball::Ball()
{
	m_isBallOutside = false;
	m_ballSpeed = 0.0001f;
	isStarted = false;	
	SetBall();
}

void Ball::SetBall()
{
	m_ball.setFillColor(sf::Color::Red);
	m_ball.setRadius(7.5f);
	m_ball.setOutlineThickness(2.0f);
	m_ball.setOutlineColor(sf::Color::White);
	m_ballSpeedVec = { 0.7f, 0.7f };
	m_ball.setPosition(sf::Vector2f(400.0f, 540.0f));
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	if (isStarted)
	{
		window.draw(m_ball);
		window.setTitle("BREAK OUT : WILD HUNT");
		m_isBallOutside = false;
		ClampBorders();
		IsBallOutside();
	}
}

void Ball::MovementControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) isStarted = true;
}

sf::CircleShape Ball::GetBall()
{
	return sf::CircleShape(m_ball);
}

void Ball::ClampBorders()
{
	auto ballPos = m_ball.getPosition();
	auto screenSize = m_window.getWindow().getSize();
	m_ballSpeedVec.x += m_ballSpeed;
	m_ballSpeedVec.y += m_ballSpeed;
	m_ball.setPosition(ballPos.x - m_ballSpeedVec.x, ballPos.y - m_ballSpeedVec.y);
	if (ballPos.x <= 0) m_ballSpeedVec.x = -abs(m_ballSpeedVec.x);
	if (ballPos.x >= screenSize.x) m_ballSpeedVec.x = abs(m_ballSpeedVec.x);
	if (ballPos.y <= 0) m_ballSpeedVec.y = -abs(m_ballSpeedVec.y);
	if (ballPos.y >= screenSize.y) m_isBallOutside = true;
}

bool Ball::IsBallOutside() const
{
	return m_isBallOutside;
}

Ball::~Ball()
{
}