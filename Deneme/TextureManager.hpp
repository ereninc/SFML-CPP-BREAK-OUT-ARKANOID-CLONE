#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
public:
	TextureManager();
	sf::Texture textureBrick;
	sf::Texture textureDamagedBrick;
	sf::Texture textureWall;
	std::string RandomBrick();
	std::string DamagedBrick();
	std::string RandomWall();
	void ImportTextures();
	sf::Texture GetRandomBrickTexture();
	sf::Texture GetDamagedBrickTexture();
	sf::Texture GetWall();
private:
	std::map<std::string, sf::Texture> textures;
};