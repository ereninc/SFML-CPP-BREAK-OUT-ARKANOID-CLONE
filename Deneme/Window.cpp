#include "Window.hpp"
#include <iostream>
#include "WindowInterface.hpp"

Window::Window()
{
	SetWindow(800,600, "BREAK OUT!");
}

void Window::SetWindow(unsigned int width, unsigned int height, sf::String title)
{
	m_sfmlWindow.create(sf::VideoMode(width, height), title);
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
		if (event.type == sf::Event::MouseMoved)
		{
			float x = event.mouseMove.x;
			float y = event.mouseMove.y;
			for (auto next:m_memberList)
			{
				if (next->isOn(x, y))
				{
					next->MouseMove(x, y);
				}
				else
				{
					next->isNotOn();
				}
			}
		} 
		if (event.type == sf::Event::MouseButtonPressed)
		{
			float x = event.mouseButton.x;
			float y = event.mouseButton.y;
			for (auto next : m_memberList)
			{
				if (next->isOn(x, y))
				{
					next->MouseOnEnable(event.mouseButton);
				}
				else
				{
					next->isNotOn();
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			float x = event.mouseButton.x;
			float y = event.mouseButton.y;
			for (auto next : m_memberList)
			{
				if (next->isOn(x, y))
				{
					next->MouseOnDisable(event.mouseButton);
				}
				else
				{
					next->isNotOn();
				}
			}
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

void Window::AddMember(WindowInterface* newMember)
{
	m_memberList.push_back(newMember);
}
