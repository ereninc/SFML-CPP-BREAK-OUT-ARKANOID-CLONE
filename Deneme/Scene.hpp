#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Scene 
{
public:
	Scene();
	void CreateScene(float sceneWidth, float sceneHeight, float cellSize);
	void DrawScene(sf::RenderWindow& window);

private:
	int m_lineCount;
	int m_columnCount;
	float m_cellSize;
	sf::RectangleShape m_lineCell;
	sf::RectangleShape m_columnCell;
};