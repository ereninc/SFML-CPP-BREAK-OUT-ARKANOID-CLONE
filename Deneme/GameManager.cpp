#include "GameManager.hpp"

GameManager::GameManager()
{
	m_shape.setRadius(30.0f);
	m_shape.setFillColor(sf::Color::Magenta);
	m_incVal = 1.0f;
	m_posX = 10.0f;
	m_frameRate = 1.0f / 60.0f;
}

GameManager::~GameManager()
{
}

void GameManager::InputControl()
{
	m_window.EventControl();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_incVal = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_incVal = -1.0f;
	}
}

void GameManager::UpdateScene()
{
	if (m_deltaTime.asSeconds() >= m_frameRate)
	{
		m_posX += m_incVal;
		m_shape.setPosition(m_posX, 300);
		m_deltaTime -= sf::seconds(m_frameRate);
	}
}

void GameManager::DrawScene()
{
	m_window.StartDrawing();
	m_window.Draw(m_shape);
	m_window.EndDrawing();
}

void GameManager::RestartClock()
{
	m_deltaTime += m_clock.restart();
}

bool GameManager::isFinished()
{
	return m_window.isClosed();
}
