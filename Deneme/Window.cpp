#include "Window.hpp"
#include <iostream>

Window::Window()
{
	SetWindow(600, 800, "BREAK OUT!");
}

void Window::SetWindow(unsigned int width, unsigned int height, sf::String title)
{
	m_sfmlWindow.create(sf::VideoMode(width, height), title);
	m_sfmlWindow.setFramerateLimit(60);
}

void Window::StartDrawing()
{
	m_sfmlWindow.clear(sf::Color(63, 77, 99, 255));
}

void Window::EndDrawing()
{
	m_sfmlWindow.display();
}

bool Window::isClosed()
{
	return !m_sfmlWindow.isOpen();
}

void Window::EventControl()
{
	sf::Event event;
	while (m_sfmlWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_sfmlWindow.close();
		}
	}
}

void Window::Draw(sf::Drawable& shape)
{
	//m_sfmlWindow.draw(shape);
}

sf::RenderWindow& Window::getWindow()
{
	return m_sfmlWindow;
}