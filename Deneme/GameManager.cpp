#include "GameManager.hpp"
#include "Button.hpp"
#include <iostream>

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
	//m_window.Draw(m_shape);
	MenuDraw();
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

void GameManager::Click()
{
	std::cout << "Method called" << std::endl;
}

void GameManager::NewGameButton()
{
	std::cout << "Game will start in 3.. 2.. 1!" << std::endl;
}

void GameManager::QuitGameButton()
{
	std::cout << "Thanks for not playing." << std::endl;
	exit(0); 
}

void GameManager::MenuSet()
{
	if (font.loadFromFile("piksel.ttf") != false)
	{
		m_newGameButton.Font(font);
		m_quitButton.Font(font);
	}
	m_newGameButton.Text("New Game");
	m_newGameButton.Color(sf::Color::Magenta);
	m_newGameButton.OutlineColor(sf::Color::White); 
	m_newGameButton.Position(340, 400);
	m_window.AddMember(&m_newGameButton);
	auto startFunction = std::bind(&GameManager::NewGameButton, this);
	m_newGameButton.AddFunction(startFunction);

	m_quitButton.Text("Quit");
	m_quitButton.Color(sf::Color::Magenta);
	m_quitButton.OutlineColor(sf::Color::White);
	m_quitButton.Position(375, 480);
	m_window.AddMember(&m_quitButton);
	auto exitFunction = std::bind(&GameManager::QuitGameButton, this);
	m_quitButton.AddFunction(exitFunction);
}

void GameManager::MenuDraw()
{
	m_newGameButton.Draw(m_window.getWindow());
	m_quitButton.Draw(m_window.getWindow());
}
