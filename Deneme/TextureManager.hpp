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
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;
	void ImportTextures();
	sf::Texture GetBrickTexture();
private:
	std::map<std::string, sf::Texture> textures;
};