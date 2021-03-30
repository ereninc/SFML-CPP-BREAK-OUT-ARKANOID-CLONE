#include "Scene.hpp"
#include <iostream>

Scene::Scene()
{
	m_lineCell.setFillColor(sf::Color::Green);
	m_columnCell.setFillColor(sf::Color::Green);
}

void Scene::CreateScene(float sceneWidth, float sceneHeight, float cellSize)
{
	m_columnCount = sceneWidth / cellSize;
	m_lineCount = sceneHeight / cellSize;
	m_cellSize = cellSize;
	m_lineCell.setSize({ sceneWidth,1 });
	m_columnCell.setSize({ 1,sceneHeight });
	m_brick.InstantiateBricks();
	m_ball.SetBall();
}

void Scene::DrawScene(sf::RenderWindow& window)
{	
	m_brick.BrickDraw(window);
	m_ball.MovementControl();
	m_ball.DrawBall(window);
	m_player.PlayerMovement();
	m_player.DrawPlayer(window);
	CheckCollisions();
	

#pragma region Grid
	/*sf::Vector2f pos;
	for (int line = 0; line < m_lineCount; line++)
	{
		pos.x = 0;
		pos.y = line * m_cellSize;
		m_lineCell.setPosition(pos);
		window.draw(m_lineCell);
	}
	for (int column = 0; column < m_columnCount; column++)
	{
		pos.x = column * m_cellSize;
		pos.y = 0;
		m_columnCell.setPosition(pos);
		window.draw(m_columnCell);
	}*/
#pragma endregion
}

void Scene::CheckCollisions()
{
	//player - ball
	if (m_player.GetPlayer().getGlobalBounds().intersects(m_ball.GetBall().getGlobalBounds()))
	{
		std::cout << "Touched!" << std::endl;
		isCollided = true;
		m_ball.m_ballSpeedVec.y = abs(m_ball.m_ballSpeedVec.y);
	}

	//ball - bricks
	/*if (m_brick.GetBrick().getGlobalBounds().intersects(m_ball.GetBall().getGlobalBounds()))
	{
		std::cout << "Brick Touched!" << std::endl;
		isCollided = true;
		m_ball.m_ballSpeedVec.x = abs(m_ball.m_ballSpeedVec.x);
	}*/
}