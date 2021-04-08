#include "TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

TextureManager::TextureManager() 
{
}

void TextureManager::LoadTextures(const std::string& name, const std::string& filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);
	this->textures[name] = tex;
	return;
}

sf::Texture& TextureManager::GetRef(const std::string& texture)
{
	return this->textures.at(texture);
}