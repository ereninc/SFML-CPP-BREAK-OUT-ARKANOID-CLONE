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
	InstantiateBricks();
}

void Scene::DrawScene(sf::RenderWindow& window)
{	
	std::cout << "Scene is Drawing" << std::endl;
	sf::Vector2f pos;

	float xOffset = 20.0f;
	float yOffset = 0.0f;
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			window.draw(m_brick);
			m_brick.setPosition(sf::Vector2f(0.0f, 0.0f));
			auto brickPos = m_brick.getPosition();
			m_brick.setPosition(brickPos.x + 20 * 6 * x, brickPos.y + 40 * y);
		}
	}

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

void Scene::InstantiateBricks()
{
	std::cout << "Bricks are instantiating.." << std::endl;
	m_brick.setFillColor(sf::Color::Cyan);
	m_brick.setSize(sf::Vector2f(80.0f, 20.0f));

}

sf::Vector2f Scene::brickPos()
{
	return m_brick.getPosition();
}
