#include "Scene.hpp"
#include <iostream>

Scene::Scene()
{
}

void Scene::CreateScene()
{
	SpawnBricks();
	DrawWalls();
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

void Scene::SpawnBricks()
{
	float xOffset = 20.0f;
	float yOffset = 0.0f;
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 15; y++)
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
		std::cout << "top player'a dokundu!" << std::endl;
		m_ball.m_ballSpeedVec.y = abs(m_ball.m_ballSpeedVec.y);
	}

	//ball - bricks carpisma
	for (int i = 0; i < bricks.size(); i++)
	{
		sf::FloatRect ballBounds = m_ball.GetBall().getGlobalBounds();
		sf::FloatRect brickBounds = bricks[i].GetBrick().getGlobalBounds();
		if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y < bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x < bricks[i].GetBrick().getPosition().x)
		{
			//std::cout << "brick ile carpisti" << std::endl;
			/*m_ball.m_ballSpeedVec.x = -abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);*/
			m_ball.m_ballSpeedVec.x *= -1; 
			m_ball.m_ballSpeedVec.y *= -1;
			bricks.erase(bricks.begin() + i);
		}
		else if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y < bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x > bricks[i].GetBrick().getPosition().x)
		{
			/*m_ball.m_ballSpeedVec.x = abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);*/
			m_ball.m_ballSpeedVec.x *= -1;
			m_ball.m_ballSpeedVec.y *= -1;
			bricks.erase(bricks.begin() + i);
		}
		else if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y > bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x > bricks[i].GetBrick().getPosition().x)
		{
			/*m_ball.m_ballSpeedVec.x = -abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);*/
			m_ball.m_ballSpeedVec.x *= 1;
			m_ball.m_ballSpeedVec.y *= -1;
			bricks.erase(bricks.begin() + i);
		}
		else if (brickBounds.intersects(ballBounds) && m_ball.GetBall().getPosition().y > bricks[i].GetBrick().getPosition().y && 
			m_ball.GetBall().getPosition().x < bricks[i].GetBrick().getPosition().x)
		{
			/*m_ball.m_ballSpeedVec.x = abs(m_ball.m_ballSpeedVec.x);
			m_ball.m_ballSpeedVec.y = -abs(m_ball.m_ballSpeedVec.y);*/
			m_ball.m_ballSpeedVec.x *= 1;
			m_ball.m_ballSpeedVec.y *= -1;
			bricks.erase(bricks.begin() + i);
		}
	}
}