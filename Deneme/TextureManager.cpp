#include "TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>


int random;
//Bricks-stage 1
std::string blueBrick = "resimler/Bricks/brick_blue_small.png";
std::string greenBrick = "resimler/Bricks/brick_green_small.png";
std::string pinkBrick = "resimler/Bricks/brick_pink_small.png";
std::string violetBrick = "resimler/Bricks/brick_violet_small.png";
std::string yellowBrick = "resimler/Bricks/brick_yellow_small.png";
//Damaged Bricks-stage 2
std::string blueDBrick = "resimler/Bricks/brick_blue_small_cracked.png";
std::string greenDBrick = "resimler/Bricks/brick_green_small_cracked.png";
std::string pinkDBrick = "resimler/Bricks/brick_pink_small_try.png";
std::string violetDBrick = "resimler/Bricks/brick_violet_small_cracked.png";
std::string yellowDBrick = "resimler/Bricks/brick_yellow_small_cracked.png";
//Walls
std::string greenWall = "resimler/Walls/brick.png";
std::string blueWall = "resimler/Walls/brick_blue.png";
std::string pinkWall = "resimler/Walls/brick_pink_side.png";
std::string redWall = "resimler/Walls/brick_red.png";


TextureManager::TextureManager()
{
}

std::string TextureManager::RandomBrick()
{
	srand(time(NULL));
	random = rand() % 5 + 1;
	if (random == 1) return blueBrick;
	if (random == 2) return greenBrick;
	if (random == 3) return pinkBrick;
	if (random == 4) return violetBrick;
	if (random == 5) return yellowBrick;
}

std::string TextureManager::DamagedBrick()
{	
	if (random == 1) return blueDBrick;
	if (random == 2) return greenDBrick;
	if (random == 3) return pinkDBrick;
	if (random == 4) return violetDBrick;
	if (random == 5) return yellowDBrick;
}

std::string TextureManager::RandomWall()
{
	srand(time(NULL));
	int randomWall = rand() % 4 + 1;
	if (randomWall == 1) return greenWall;
	if (randomWall == 2) return blueWall;
	if (randomWall == 3) return pinkWall;
	if (randomWall == 4) return redWall;
}

void TextureManager::ImportTextures()
{
	textureBrick.loadFromFile(RandomBrick());
	textureDamagedBrick.loadFromFile(DamagedBrick());
	textureWall.loadFromFile(RandomWall());
}

sf::Texture TextureManager::GetRandomBrickTexture()
{
	return sf::Texture(textureBrick);
}

sf::Texture TextureManager::GetDamagedBrickTexture()
{
	return sf::Texture(textureDamagedBrick);
}

sf::Texture TextureManager::GetWall()
{
	return sf::Texture(textureWall);
}




