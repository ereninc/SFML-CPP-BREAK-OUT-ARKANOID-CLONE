#pragma once
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Player 
{
public:
	Player();
	void InstantiatePlayer();
	void DrawPlayer(sf::RenderWindow& window);
	sf::Vector2f GetSize();
	void PlayerMovement();
	sf::Vector2f GetPosition();
	sf::Vector2f m_position;
	float GetPlayerPosX();
	float GetPlayerPosY();
	~Player();
private:
	Window m_window;
	sf::RectangleShape m_playerShape;
	float m_playerMoveVal = 0.0f;
	sf::Vector2f m_size;
};