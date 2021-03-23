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
	std::cout << "Scene is Creating" << std::endl;
	m_columnCount = sceneWidth / cellSize;
	m_lineCount = sceneHeight / cellSize;
	m_cellSize = cellSize;
	m_lineCell.setSize({ sceneWidth,1 });
	m_columnCell.setSize({ 1,sceneHeight });
}

void Scene::DrawScene(sf::RenderWindow& window)
{	
	std::cout << "Scene is Drawing" << std::endl;
	sf::Vector2f pos;
	//window.draw(m_Yem);
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
	}
}