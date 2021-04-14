#include "GameManager.hpp"
#include <iostream>

GameManager::GameManager()
{
	m_isClosed = false;
	auto size = m_window.getWindow().getSize();
	m_cellSize = 20.0f;
	m_scene.CreateScene();
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
	m_scene.DrawScene(m_window.getWindow());
	m_window.EndDrawing();
}

void GameManager::RestartClock()
{
	m_deltaTime += m_clock.restart();
}

bool GameManager::isFinished()
{
	if (m_isClosed)
	{
		return true;
	}
	return m_window.isClosed();
}
