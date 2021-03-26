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
	sf::Vector2f m_playerPosition;
	~Player();
private:
	Window m_window;
	float m_playerMoveVal = 0.0f;
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	sf::RectangleShape m_playerShape;
};