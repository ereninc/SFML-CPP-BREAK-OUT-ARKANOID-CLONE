#include "Ball.hpp"
#include <iostream>

Ball::Ball()
{
}

void Ball::SetBall()
{
	m_ball.setFillColor(sf::Color::Red);
	m_ball.setRadius(7.5f);
	m_ball.setOutlineThickness(2.0f);
	m_ball.setOutlineColor(sf::Color::White);
	m_ballSpeedVec = {0.7f, 0.7f};
	m_ball.setPosition(sf::Vector2f(400.0f, 540.0f));
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	if (isStarted)
	{
		window.draw(m_ball);
		m_isBallOutside = false;
		ClampBorders();
		IsBallOutside();
		//CheckPlayerCollision();
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

void Ball::ClampBorders()
{
	auto ballPos = GetPosisiton();
	auto screenSize = m_window.getWindow().getSize();
	auto playerPos = m_player.GetPosition();
	m_ballSpeedVec.x += m_ballSpeed;
	m_ballSpeedVec.y += m_ballSpeed;
	m_ball.setPosition(ballPos.x - m_ballSpeedVec.x, ballPos.y - m_ballSpeedVec.y);
	if (ballPos.x <= 0) m_ballSpeedVec.x = -abs(m_ballSpeedVec.x);
	if (ballPos.x >= screenSize.x) m_ballSpeedVec.x = abs(m_ballSpeedVec.x);
	if (ballPos.y <= 0) m_ballSpeedVec.y = -abs(m_ballSpeedVec.y);
	if (ballPos.y >= screenSize.y) m_ballSpeedVec.y = abs(m_ballSpeedVec.y);
		//m_isBallOutside = true;
		
	if (ballPos.y >= playerPos.y && ballPos.y <= playerPos.y + 5)
	{
		std::cout << "SAME Y" << std::endl;
		std::cout << "playerPos.y : " << playerPos.y << std::endl;
		std::cout << "ballPos.y : " << ballPos.y << std::endl;
	}
	if ((ballPos.x >= playerPos.x && ballPos.x <= (playerPos.x + 120.0f)))
	{
		//std::cout << "SAME X" << std::endl;
		//m_ballSpeedVec.y = abs(m_ballSpeedVec.y);
	}
}

bool Ball::IsBallOutside()
{
	//std::cout << m_isBallOutside << std::endl;
	return m_isBallOutside;
}

Ball::~Ball()
{
}