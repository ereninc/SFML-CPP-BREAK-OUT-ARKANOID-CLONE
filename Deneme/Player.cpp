#include "Player.hpp"

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
	auto m_playerPos = m_playerShape.getPosition();
	window.draw(m_playerShape);
	m_playerShape.setPosition(m_playerPos.x + m_playerMoveVal, m_playerPos.y);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_playerMoveVal = 0.0f;
	}
}
