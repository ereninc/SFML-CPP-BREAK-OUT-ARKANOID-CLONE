#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
public:
	TextureManager();
	/*void LoadTextures(const std::string& name, const std::string &filename);
	sf::Texture& GetRef(const std::string& texture);*/
	sf::Texture textureBrick;
	std::string Random();
	void ImportTextures();
	sf::Texture GetRandomBrickTexture();
	sf::Texture GetDamagedBrickTexture();
private:
	std::map<std::string, sf::Texture> textures;
};