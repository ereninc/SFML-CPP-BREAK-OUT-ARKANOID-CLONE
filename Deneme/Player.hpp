#pragma once
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Player 
{
public:
	Player(float x = 400.0f, float y = 760.0f);
	void Init();
	void DrawPlayer(sf::RenderWindow& window);
	void PlayerMovement();
	void BorderCheck();
	sf::RectangleShape GetPlayer();
	sf::Vector2f GetPosition();
	~Player();
private:
	Window m_window;
	float m_playerSpeed = 0.0f;
	sf::RectangleShape m_playerShape;
};