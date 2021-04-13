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
	std::string RandomBrick();
	std::string DamagedBrick();
	void ImportTextures();
	sf::Texture GetRandomBrickTexture();
	sf::Texture GetDamagedBrickTexture();
private:
	std::map<std::string, sf::Texture> textures;
};