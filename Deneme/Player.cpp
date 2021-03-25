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
	auto playerPos = m_playerShape.getPosition();
	auto screenSize = m_window.getWindow().getSize();
	if (playerPos.x + 120.0f <= screenSize.x && playerPos.x >= 0)
	{
		m_playerShape.setPosition(playerPos.x + m_playerMoveVal, playerPos.y);
		m_playerMoveVal = 0.0f;
	}
	//rezil bi fix oldu ***BURAYA DÖN GERÝ***
	if (playerPos.x <= 0)
	{
		m_playerShape.setPosition(playerPos.x + 1.0f, playerPos.y);
	}
	if (playerPos.x + 120.0f >= screenSize.x)
	{
		m_playerShape.setPosition(playerPos.x - 1.0f, playerPos.y);
	}
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