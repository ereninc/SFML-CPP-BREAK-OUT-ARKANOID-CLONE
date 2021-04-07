#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "Brick.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Wall.hpp"

class Scene 
{
public:
	Scene();
	void CreateScene();
	void DrawScene(sf::RenderWindow& window);
	void SpawnBricks();
	void DrawWalls();
	void CheckCollisions();
private:
	Brick m_brick;
	Player m_player;
	Ball m_ball;
	Wall m_wall;
	std::vector<Brick> bricks;
	std::vector<Wall> walls;
};