#include "Scene.hpp"
#include <iostream>

Scene::Scene()
{
	std::cout << "Scene Constructor" << std::endl;
	m_lineCell.setFillColor(sf::Color::Green);
	m_columnCell.setFillColor(sf::Color::Green);
}

void Scene::CreateScene(float sceneWidth, float sceneHeight, float cellSize)
{
	std::cout << "Creating scene method." << std::endl;
	m_columnCount = sceneWidth / cellSize;
	m_lineCount = sceneHeight / cellSize;
	m_cellSize = cellSize;
	m_lineCell.setSize({ sceneWidth,1 });
	m_columnCell.setSize({ 1,sceneHeight });
	m_brick.InstantiateBricks();
	m_player.InstantiatePlayer();
	m_ball.SetBall();
}

void Scene::DrawScene(sf::RenderWindow& window)
{	
	//std::cout << "Drawing the scene." << std::endl;
	m_brick.BrickDraw(window);
	m_player.DrawPlayer(window);
	m_player.PlayerMovement();
	m_ball.DrawBall(window);

	//GRID
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
}