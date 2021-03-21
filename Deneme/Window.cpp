#include "Window.hpp"
#include <iostream>

Window::Window()
{
	SetWindow(800,600, "SFML Deneme2");
}

void Window::SetWindow(unsigned int width, unsigned int height, sf::String title)
{
	m_window.create(sf::VideoMode(width, height), title);
}

void Window::StartDrawing()
{
	m_window.clear();
}

void Window::EndDrawing()
{
	m_window.display();
}

bool Window::isClosed()
{
	return !m_window.isOpen();
}

void Window::EventControl()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		if (event.type == sf::Event::MouseMoved)
		{
			std::cout << event.mouseMove.x << " , " << event.mouseMove.y << std::endl;
		}
	}
}

void Window::Draw(sf::Drawable& shape)
{
	m_window.draw(shape);
}
