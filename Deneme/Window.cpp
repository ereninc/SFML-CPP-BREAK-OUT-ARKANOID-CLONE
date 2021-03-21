#include "Window.hpp"
#include <iostream>

Window::Window()
{
	SetWindow(800,600, "SFML Deneme2");
}

void Window::SetWindow(unsigned int width, unsigned int height, sf::String title)
{
	m_sfmlWindow.create(sf::VideoMode(width, height), title);
}

void Window::StartDrawing()
{
	m_sfmlWindow.clear();
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
		if (event.type == sf::Event::MouseMoved)
		{
			std::cout << event.mouseMove.x << " , " << event.mouseMove.y << std::endl;
		}
	}
}

void Window::Draw(sf::Drawable& shape)
{
	m_sfmlWindow.draw(shape);
}

sf::RenderWindow& Window::getWindow()
{
	return m_window;
}