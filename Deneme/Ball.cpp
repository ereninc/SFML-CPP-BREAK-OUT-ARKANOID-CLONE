#include "Ball.hpp"
#include <iostream>

std::string fileName2 = "";
Ball::Ball()
{
	Random();
	m_isBallOutside = false;
	m_ballSpeed = 0.0001f;
	isStarted = false;	
	SetBall();
}

void Ball::SetBall()
{
	if (!m_ballTexture.loadFromFile(fileName2))
		std::cout << "PNG YOK" << std::endl;
	else {
		m_ballSprite.setTexture(m_ballTexture);
		m_ballSprite.setScale(.05, .05);
		m_ballSprite.setTextureRect(sf::IntRect(79.0f, 79.0f, 370.0f, 380.0f));
	}
	m_ballSpeedVec = { 6.0f, 6.0f };
	m_ballSprite.setPosition(sf::Vector2f(240.0f, 740.0f));
}

void Ball::Random()
{
	srand(time(NULL));
	int a = rand() % 6 + 1;
	std::cout << "Ball Texture Random : " << a << std::endl;
	if (a == 1) fileName2 = "resimler/Balls/ball_blue.png";
	if (a == 2) fileName2 = "resimler/Balls/ball_green.png";
	if (a == 3) fileName2 = "resimler/Balls/ball_orange.png";
	if (a == 4) fileName2 = "resimler/Balls/ball_red.png";
	if (a == 5) fileName2 = "resimler/Balls/ball_silver.png";
	if (a == 6) fileName2 = "resimler/Balls/ball_yellow.png";
}

void Ball::DrawBall(sf::RenderWindow& window)
{
	if (isStarted)
	{
		window.draw(m_ballSprite);
		if (!m_isBallOutside) window.setTitle("BREAK OUT : WILD HUNT       -       FPS: 60 (VSYNC ON)");
		else if (m_isBallOutside) window.setTitle("*GAME OVER* PRESS SPACE TO RESPAWN");
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

	if (m_isBallOutside)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
		{
			m_ballSprite.setPosition(sf::Vector2f(300.0f, 700.0f));
			m_ballSpeedVec = { 6.0f, 6.0f };
			m_isBallOutside = false;
		}
	}
}

sf::Sprite Ball::GetBall()
{
	return sf::Sprite(m_ballSprite);
}

void Ball::ClampBorders()
{
	auto ballPos = m_ballSprite.getPosition();
	auto screenSize = m_window.getWindow().getSize();
	m_ballSpeedVec.x += m_ballSpeed;
	m_ballSpeedVec.y += m_ballSpeed;
	m_ballSprite.setPosition(ballPos.x - m_ballSpeedVec.x, ballPos.y - m_ballSpeedVec.y);
	if (ballPos.x <= 40) m_ballSpeedVec.x = -abs(m_ballSpeedVec.x);
	if (ballPos.x >= screenSize.x - 45) m_ballSpeedVec.x = abs(m_ballSpeedVec.x);
	if (ballPos.y <= 40) m_ballSpeedVec.y = -abs(m_ballSpeedVec.y);
	if (ballPos.y >= screenSize.y) 
	{
		m_isBallOutside = true;
		std::cout << "GAME OVER - PRESS SPACE TO RESPAWN!" << std::endl;
	}
}

bool Ball::IsBallOutside() const
{
	return m_isBallOutside;
}

Ball::~Ball()
{
}