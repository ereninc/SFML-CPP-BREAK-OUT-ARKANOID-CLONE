#include "Player.hpp"
#include <iostream>

std::string fileName = "";
Player::Player(float x, float y)
{
	Random();
	m_playerShape.setPosition(x, y);
	if (!m_playerTexture.loadFromFile(fileName))
		std::cout << "PNG YOK" << std::endl;
	else {
		m_playerSprite.setTexture(m_playerTexture);
		m_playerSprite.setScale(.258, .2);
		m_playerSprite.setTextureRect(sf::IntRect(24.0f, 180.0f, 464.0f, 105.0f));
	}
	Init();
}

void Player::Init()
{
	m_playerShape.setFillColor(sf::Color::Transparent);
	m_playerShape.setSize(sf::Vector2f(120.0f, 20.0f));
	m_playerSprite.setPosition(m_playerShape.getPosition());
}

void Player::Random()
{
	srand(time(NULL));
	int a = rand() % 5 + 1;
	std::cout << "Player rnd : " << a << std::endl;
	if (a == 1) fileName = "bat_black.png";
	if (a == 2) fileName = "bat_blue.png";
	if (a == 3) fileName = "bat_orange.png";
	if (a == 4) fileName = "bat_pink.png";
	if (a == 5) fileName = "bat_yellow.png";
}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_playerShape);
	window.draw(m_playerSprite);
	m_playerSprite.setPosition(m_playerShape.getPosition());
}

void Player::PlayerMovement()
{
	BorderCheck();
	//inputlar
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_playerShape.move(m_playerSpeed = 15.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_playerShape.move(m_playerSpeed = -15.0f, 0);
	}
}

void Player::BorderCheck()
{
	//cerceve siniri
	sf::FloatRect playerBounds = m_playerShape.getGlobalBounds();
	if (playerBounds.left <= 20.0f)
	{
		m_playerShape.setPosition(25.0f, m_playerShape.getPosition().y);
	}
	else if (playerBounds.left + playerBounds.width >= m_window.getWindow().getSize().x - 20.0f)
	{
		m_playerShape.setPosition(m_window.getWindow().getSize().x - playerBounds.width - 25.0f, m_playerShape.getPosition().y);
	}
}

sf::RectangleShape Player::GetPlayer()
{
	return m_playerShape;
}

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(m_playerShape.getPosition());
}

Player::~Player()
{
}