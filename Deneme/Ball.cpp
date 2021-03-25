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
	window.draw(m_ball);
	m_ball.setPosition(sf::Vector2f(400.0f, 540.0f));
}