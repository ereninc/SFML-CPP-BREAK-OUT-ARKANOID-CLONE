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

void TextureManager::ImportTextures()
{
	t1.loadFromFile("resimler/Bricks/brick_blue_small.png");
	t2.loadFromFile("resimler/Bricks/brick_green_small.png");
	t3.loadFromFile("resimler/Bricks/brick_pink_small.png");
	t4.loadFromFile("resimler/Bricks/brick_violet_small.png");
	t5.loadFromFile("resimler/Bricks/brick_yellow_small.png");
}

sf::Texture TextureManager::GetBrickTexture()
{
	return sf::Texture(t1);
}


