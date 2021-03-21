#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

int main()
{
	GameManager gameManager;
	while (!gameManager.isFinished())
	{
		gameManager.InputControl();
		gameManager.UpdateScene();
		gameManager.DrawScene();
		gameManager.RestartClock();
	}
	return 0;
}