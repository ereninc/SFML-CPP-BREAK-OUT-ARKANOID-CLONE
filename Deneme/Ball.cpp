#include "Ball.hpp"
#include <iostream>

std::string fileName2 = "";
Ball::Ball()
{
	Random();
	m_isBallOutside = false;
	m_ballSpeed = 0.0001f;
	isStarted = false;	
	if (!m_ballTexture.loadFromFile(fileName2))
		std::cout << "PNG YOK" << std::endl;
	else {
		m_ballSprite.setTexture(m_ballTexture);
		m_ballSprite.setScale(.05, .05);
		m_ballSprite.setTextureRect(sf::IntRect(79.0f, 79.0f, 370.0f, 380.0f));
	}
	SetBall();
}

void Ball::SetBall()
{
	m_ball.setFillColor(sf::Color::Transparent);
	m_ball.setSize(sf::Vector2f(10.0f, 10.0f));
	m_ballSpeedVec = { 5.7f, 5.7f };
	m_ball.setPosition(sf::Vector2f(400.0f, 740.0f));
}

void Ball::Random()
{
	srand(time(NULL));
	int a = rand() % 6 + 1;
	std::cout << "Ball rnd : " << a << std::endl;
	if (a == 1) fileName2 = "ball_blue.png";
	if (a == 2) fileName2 = "ball_green.png";
	if (a == 3) fileName2 = "ball_orange.png";
	if (a == 4) fileName2 = "ball_red.png";
	if (a == 5) fileName2 = "ball_silver.png";
	if (a == 6) fileName2 = "ball_yellow.png";
	else fileName2 = "ball_yellow.png";
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	if (isStarted)
	{
		window.draw(m_ball);
		window.draw(m_ballSprite);
		m_ballSprite.setPosition(m_ball.getPosition());
		window.setTitle("BREAK OUT : WILD HUNT       -       FPS: 60 (VSYNC ON)");
		m_isBallOutside = false;
		ClampBorders();
		IsBallOutside();
	}
}

void Ball::MovementControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) isStarted = true;
}

sf::RectangleShape Ball::GetBall()
{
	return sf::RectangleShape(m_ball);
}

void Ball::ClampBorders()
{
	auto ballPos = m_ball.getPosition();
	auto screenSize = m_window.getWindow().getSize();
	m_ballSpeedVec.x += m_ballSpeed;
	m_ballSpeedVec.y += m_ballSpeed;
	m_ball.setPosition(ballPos.x - m_ballSpeedVec.x, ballPos.y - m_ballSpeedVec.y);
	if (ballPos.x <= 40) m_ballSpeedVec.x = -abs(m_ballSpeedVec.x);
	if (ballPos.x >= screenSize.x - 40) m_ballSpeedVec.x = abs(m_ballSpeedVec.x);
	if (ballPos.y <= 40) m_ballSpeedVec.y = -abs(m_ballSpeedVec.y);
	if (ballPos.y >= screenSize.y) m_isBallOutside = true;
}

bool Ball::IsBallOutside() const
{
	return m_isBallOutside;
}

Ball::~Ball()
{
}