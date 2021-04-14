#include "Scene.hpp"
#include <iostream>

Scene::Scene()
{
}

void Scene::CreateScene()
{
	SpawnBricks();
	DrawWalls();
	std::cout << "----------------------------------------------------------------------\nBaslamak icin SPACE tusuna basin\nHareket etmek icin SAG VE SOL YON TUSLARINA basin\nYeniden dogmak icin SPACE tusuna basin" << std::endl;
}

void Scene::DrawScene(sf::RenderWindow& window)
{
	for (auto i : bricks)
	{
		i.BrickDraw(window);
	}
	for (auto j : walls)
	{
		j.DrawWall(window);
	}
	m_ball.DrawBall(window);
	m_ball.MovementControl();
	m_player.DrawPlayer(window);
	m_player.PlayerMovement();
	CheckCollisions();
}

void Scene::SpawnBricks()
{
	float xOffset = 20.0f;
	float yOffset = 0.0f;
	int line = 6;
	int column = 15;
	for (int x = 0; x < line; x++)
	{
		for (int y = 0; y < column; y++)
		{
			auto brickPos = m_brick.GetBrick().getPosition();
			bricks.push_back(Brick(brickPos.x + (15 * 6 * x) + 35.f, brickPos.y + (30 * y) + 40.0f));
		}
	}
}

void Scene::DrawWalls()
{
	float x = 0;
	float y = 0;
	for (int x = 0; x < 27; x++)
	{
		auto wallPos = m_wall.GetWall().getPosition();
		walls.push_back(Wall(wallPos.x + (x * 22) + 4.f, wallPos.y + (22 * y) + 5.0f));
		if (x == 26)
		{
			for (int y = 0; y < 36; y++)
			{
				auto wallPos = m_wall.GetWall().getPosition();
				walls.push_back(Wall(wallPos.x + (x * 22) + 4.f, wallPos.y + (22 * y) + 5.0f));
			}
		}
	}

	for (int y = 0; y < 36; y++)
	{
		auto wallPos = m_wall.GetWall().getPosition();
		walls.push_back(Wall(wallPos.x + (x * 22) + 4.f, wallPos.y + (22 * y) + 5.0f));
	}
}

void Scene::CheckCollisions()
{
	//player - ball carpisma
	if (m_player.GetPlayer().getGlobalBounds().intersects(m_ball.GetBall().getGlobalBounds()))
	{
		//std::cout << "top player'a dokundu!" << std::endl;
		m_ball.m_ballSpeedVec.y = abs(m_ball.m_ballSpeedVec.y);
	}

	//ball - bricks carpisma
	for (int i = 0; i < bricks.size(); i++)
	{
		sf::FloatRect ballBounds = m_ball.GetBall().getGlobalBounds();
		sf::FloatRect brickBounds = bricks[i].GetBrick().getGlobalBounds();
		if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y < bricks[i].GetBrick().getPosition().y &&
			m_ball.GetBall().getPosition().x < bricks[i].GetBrick().getPosition().x + 40.0f)
		{
			//std::cout << "brick ile carpisti" << std::endl;
			m_ball.m_ballSpeedVec.x = -abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = abs(m_ball.m_ballSpeedVec.y);
			bricks[i].GetDamage();
			if (bricks[i].GetHealth() == 0) bricks.erase(bricks.begin() + i);
			return;
		}
		else if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y < bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x > bricks[i].GetBrick().getPosition().x + 40.0f)
		{
			m_ball.m_ballSpeedVec.x = -abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);
			bricks[i].GetDamage();
			if (bricks[i].GetHealth() == 0) bricks.erase(bricks.begin() + i);
			return;
		}
		else if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y > bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x > bricks[i].GetBrick().getPosition().x + 40.0f)
		{
			m_ball.m_ballSpeedVec.x = -abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);
			bricks[i].GetDamage();
			if (bricks[i].GetHealth() == 0) bricks.erase(bricks.begin() + i);
			return;
		}
		else if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y > bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x < bricks[i].GetBrick().getPosition().x + 40.0f)
		{
			m_ball.m_ballSpeedVec.x = abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);
			bricks[i].GetDamage();
			if (bricks[i].GetHealth() == 0) bricks.erase(bricks.begin() + i);
			return;
		}
	}
}