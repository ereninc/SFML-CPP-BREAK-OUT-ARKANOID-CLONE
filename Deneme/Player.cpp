#include "Player.hpp"
#include <iostream>

std::string fileName = "";
Player::Player(float x, float y)
{
	Random();
	m_playerShapeSprite.setPosition(x, y);
	Init();
}

void Player::Init()
{
	if (!m_playerTexture.loadFromFile(fileName))
		std::cout << "PNG YOK" << std::endl;
	else {
		m_playerShapeSprite.setTexture(m_playerTexture);
		m_playerShapeSprite.setScale(.258, .2);
		m_playerShapeSprite.setTextureRect(sf::IntRect(24.0f, 180.0f, 464.0f, 105.0f));
	}
}

void Player::Random()
{
	srand(time(NULL));
	int a = rand() % 5 + 1;
	std::cout << "Player rnd : " << a << std::endl;
	if (a == 1) fileName = "resimler/bat_black.png";
	if (a == 2) fileName = "resimler/bat_blue.png";
	if (a == 3) fileName = "resimler/bat_orange.png";
	if (a == 4) fileName = "resimler/bat_pink.png";
	if (a == 5) fileName = "resimler/bat_yellow.png";
}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_playerShapeSprite);
}

void Player::PlayerMovement()
{
	BorderCheck();
	//inputlar
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_playerShapeSprite.move(m_playerSpeed = 15.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_playerShapeSprite.move(m_playerSpeed = -15.0f, 0);
	}
}

void Player::BorderCheck()
{
	//cerceve siniri
	sf::FloatRect playerBounds = m_playerShapeSprite.getGlobalBounds();
	if (playerBounds.left <= 20.0f)
	{
		m_playerShapeSprite.setPosition(25.0f, m_playerShapeSprite.getPosition().y);
	}
	else if (playerBounds.left + playerBounds.width >= m_window.getWindow().getSize().x - 20.0f)
	{
		m_playerShapeSprite.setPosition(m_window.getWindow().getSize().x - playerBounds.width - 25.0f, m_playerShapeSprite.getPosition().y);
	}
}

sf::Sprite Player::GetPlayer()
{
	return m_playerShapeSprite;
}

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(m_playerShapeSprite.getPosition());
}

Player::~Player()
{
}