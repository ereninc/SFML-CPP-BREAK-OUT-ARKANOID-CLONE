#include "GameManager.hpp"
#include "Button.hpp"

Button button;
sf::Font font;

GameManager::GameManager()
{
	m_shape.setRadius(30.0f);
	m_shape.setFillColor(sf::Color::Cyan);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setOutlineThickness(2.0f);
	m_incVal = 1.0f;
	m_posX = 10.0f;
	m_frameRate = 1.0f / 60.0f;

	if (font.loadFromFile("piksel.ttf") != false)
	{
		button.Font(font);
	}
	button.Size(200, 50);
	button.Text("New Game");
	button.Color(sf::Color::Magenta);
	button.OutlineColor(sf::Color::White);
	button.Position(340, 400);
	m_window.AddMember(&button);
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
	button.Draw(m_window.getWindow());
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
