#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "Brick.hpp"
#include "Player.hpp"
#include "Ball.hpp"

class Scene 
{
public:
	Scene();
	void CreateScene(float sceneWidth, float sceneHeight, float cellSize);
	void DrawScene(sf::RenderWindow& window);
	void SpawnBricks();
	void CheckCollisions();
private:
	Brick m_brick;
	Player m_player;
	Ball m_ball;
	std::vector<Brick> bricks;
	int m_lineCount;
	int m_columnCount;
	float m_cellSize;
	sf::RectangleShape m_lineCell;
	sf::RectangleShape m_columnCell;
};