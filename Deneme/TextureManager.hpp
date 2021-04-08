#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
public:
	TextureManager();
	void LoadTextures(const std::string& name, const std::string &filename);
	sf::Texture& GetRef(const std::string& texture);
private:
	std::map<std::string, sf::Texture> textures;
};