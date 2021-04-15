#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager();
	std::string RandomBrick();
	std::string DamagedBrick();
	std::string RandomWall();
	void ImportBrickTextures();
	void ImportWallTextures();
	sf::Texture GetRandomBrickTexture();
	sf::Texture GetDamagedBrickTexture();
	sf::Texture GetWall();
private:
	sf::Texture textureBrick;
	sf::Texture textureDamagedBrick;
	sf::Texture textureWall;
	int randomBrick;
	int randomWall;
};