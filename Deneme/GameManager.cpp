#include "GameManager.hpp"
#include "Button.hpp"
#include <iostream>

sf::Font font;

GameManager::GameManager()
{
	m_isClosed = false;
	m_isNewGameClicked = false;
	auto size = m_window.getWindow().getSize();
	m_cellSize = 20.0f;
	m_scene.CreateScene();
	m_frameRate = 1.0f / 60.0f;
	MenuSet();	
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
	//if (m_isNewGameClicked)
	{
		m_scene.DrawScene(m_window.getWindow());
	}
	//else
	{
		//MenuDraw();
	}
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

void GameManager::Click()
{
	std::cout << "Method called" << std::endl;
}

void GameManager::NewGameButton()
{
	m_window.getWindow().setTitle("PRESS SPACE TO START!");
	m_isNewGameClicked = true;
}

void GameManager::QuitGameButton()
{
	m_isClosed = true;
	exit(0); 
}

void GameManager::MenuSet()
{
	if (font.loadFromFile("piksel.ttf") != false)
	{
		m_newGameButton.Font(font);
		m_quitButton.Font(font);
	}

	auto sceneSize = m_window.getWindow().getSize();
	auto buttonSize = sf::Vector2f(200, 50);
	float x = (sceneSize.x - buttonSize.x) / 2.0f;
	float y = (sceneSize.y - buttonSize.y) / 2.0f;

	m_newGameButton.Text("New Game");
	m_newGameButton.Color(sf::Color::Magenta);
	m_newGameButton.OutlineColor(sf::Color::White);
	m_newGameButton.Position(x + 40, y);
	m_window.AddMember(&m_newGameButton);
	auto startFunction = std::bind(&GameManager::NewGameButton, this);
	m_newGameButton.AddFunction(startFunction);

	m_quitButton.Text("Quit");
	m_quitButton.Color(sf::Color::Magenta);
	m_quitButton.OutlineColor(sf::Color::White);
	m_quitButton.Position(x + 75, y + 80);
	m_window.AddMember(&m_quitButton);
	auto exitFunction = std::bind(&GameManager::QuitGameButton, this);
	m_quitButton.AddFunction(exitFunction);
}

void GameManager::MenuDraw()
{
	m_newGameButton.Draw(m_window.getWindow());
	m_quitButton.Draw(m_window.getWindow());
}
