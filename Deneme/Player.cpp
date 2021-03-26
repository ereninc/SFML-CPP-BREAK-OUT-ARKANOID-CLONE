#include "Player.hpp"
#include <iostream>

Player::Player()
{
}

void Player::InstantiatePlayer()
{
	m_playerShape.setFillColor(sf::Color::Magenta);
	m_playerShape.setOutlineColor(sf::Color::White);
	m_playerShape.setOutlineThickness(2.0f);
	m_playerShape.setPosition(sf::Vector2f(400.0f, 560.0f));
	m_size = sf::Vector2f(120.0f, 20.0f);
	m_playerShape.setSize(m_size);
}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_playerShape);
	m_position = GetPosition();
	auto screenSize = m_window.getWindow().getSize();
	if (m_position.x + 120.0f <= screenSize.x && m_position.x >= 0)
	{
		m_playerShape.setPosition(m_position.x + m_playerMoveVal, m_position.y);
		m_playerMoveVal = 0.0f;
	}
	if (m_position.x <= 0)
	{
		m_playerShape.setPosition(m_position.x + 1.0f, m_position.y);
	}
	if (m_position.x + 120.0f >= screenSize.x)
	{
		m_playerShape.setPosition(m_position.x - 1.0f, m_position.y);
	}

	//std::cout << GetPlayerPosX() << std::endl;
}

sf::Vector2f Player::GetSize()
{
	return sf::Vector2f(m_size);
}

void Player::PlayerMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_playerMoveVal = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_playerMoveVal = -1.0f;
	}
}
 
sf::Vector2f Player::GetPosition()
{
	m_position = m_playerShape.getPosition();
	return sf::Vector2f(m_position);
}

float Player::GetPlayerPosX() const
{
	return m_playerShape.getPosition().x;
}

float Player::GetPlayerPosY() const
{
	return m_playerShape.getPosition().y;
}

Player::~Player()
{
}
