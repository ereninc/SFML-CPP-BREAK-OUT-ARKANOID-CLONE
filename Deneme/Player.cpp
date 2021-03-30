#include "Player.hpp"
#include <iostream>

Player::Player(float x, float y)
{
	m_playerShape.setPosition(x, y);
	Init();
}

void Player::Init()
{
	m_playerShape.setFillColor(sf::Color::Magenta);
	m_playerShape.setOutlineColor(sf::Color::White);
	m_playerShape.setOutlineThickness(2.0f);
	m_playerShape.setSize(sf::Vector2f(120.0f, 20.0f));
}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_playerShape);
}

void Player::PlayerMovement()
{
	BorderCheck();
	//inputlar
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_playerShape.move(m_playerSpeed = 1.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_playerShape.move(m_playerSpeed = -1.0f, 0);
	}
	//std::cout << m_playerShape.getPosition().x << " - " << m_playerShape.getPosition().y << std::endl;
}

void Player::BorderCheck()
{
	//cerceve siniri
	sf::FloatRect playerBounds = m_playerShape.getGlobalBounds();
	if (playerBounds.left <= 0.0f)
	{
		m_playerShape.setPosition(5.0f, m_playerShape.getPosition().y);
	}
	else if (playerBounds.left + playerBounds.width >= m_window.getWindow().getSize().x)
	{
		m_playerShape.setPosition(m_window.getWindow().getSize().x - playerBounds.width - 5.0f, m_playerShape.getPosition().y);
	}
}

sf::RectangleShape Player::GetPlayer()
{
	return m_playerShape;
}

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(m_playerShape.getPosition());
}

Player::~Player()
{
}
