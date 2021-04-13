#include "TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

std::string blueBrick = "resimler/Bricks/brick_blue_small.png";
std::string greenBrick = "resimler/Bricks/brick_green_small.png";
std::string pinkBrick = "resimler/Bricks/brick_pink_small.png";
std::string violetBrick = "resimler/Bricks/brick_violet_small.png";
std::string yellowBrick = "resimler/Bricks/brick_yellow_small.png";

/*
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
*/
std::string TextureManager::Random()
{
	//srand(time(NULL));
	int random = rand() % 5 + 1;
	if (random == 1) return blueBrick;
	if (random == 2) return greenBrick;
	if (random == 3) return pinkBrick;
	if (random == 4) return violetBrick;
	if (random == 5) return yellowBrick;

}
void TextureManager::ImportTextures()
{
	textureBrick.loadFromFile(Random());
}

sf::Texture TextureManager::GetRandomBrickTexture()
{
	return sf::Texture(textureBrick);
}

sf::Texture TextureManager::GetDamagedBrickTexture()
{
	return sf::Texture();
}

TextureManager::TextureManager()
{
}


