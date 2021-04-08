#include "TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

TextureManager::TextureManager() 
{
	//ImportTextures();
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
	t1.loadFromFile("resimler/brick_blue_small.png");
	t2.loadFromFile("resimler/brick_green_small.png");
	t3.loadFromFile("resimler/brick_pink_small.png");
	t4.loadFromFile("resimler/brick_violet_small.png");
	t5.loadFromFile("resimler/brick_yellow_small.png");
	t6.loadFromFile("resimler/brick.png");
	t7.loadFromFile("resimler/brick_blue.png");
	t8.loadFromFile("resimler/brick_pink_side.png");
	t9.loadFromFile("resimler/brick_red.png");
}

sf::Texture TextureManager::GetBrickTexture()
{
	srand(time(NULL));
	int a = rand() % 5 + 1;
	if (a == 1) return sf::Texture(t1);
	if (a == 2) return sf::Texture(t2);
	if (a == 3) return sf::Texture(t3);
	if (a == 4) return sf::Texture(t4);
	if (a == 5) return sf::Texture(t5);
}

sf::Texture TextureManager::GetWallTexture()
{
	srand(time(NULL));
	int a = rand() % 5 + 1;
	if (a == 1) return sf::Texture(t6);
	if (a == 2) return sf::Texture(t7);
	if (a == 3) return sf::Texture(t8);
	if (a == 4) return sf::Texture(t9);
}
