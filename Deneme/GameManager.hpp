#pragma once
#include "Window.hpp"
#include "Button.hpp"
#include "Scene.hpp"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void InputControl();
	void UpdateScene();
	void DrawScene();
	void RestartClock();
	bool isFinished();
	void Click();
	void NewGameButton();
	void QuitGameButton();
	void MenuSet();
	void MenuDraw();
	Scene m_scene;
	float m_cellSize;
private:
	Window m_window;
	bool m_isClosed;
	bool m_isNewGameClicked;
	sf::Clock m_clock;
	sf::Time m_deltaTime;
	sf::CircleShape m_shape;
	float m_incVal;
	float m_posX;
	float m_frameRate;
	Button m_newGameButton;
	Button m_quitButton;
	sf::Font m_font;
};
