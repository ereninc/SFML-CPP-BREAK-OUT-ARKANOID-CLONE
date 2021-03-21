#pragma once
#include<SFML/Graphics.hpp>
#include <vector>

class WindowInterface;

class Window
{
public:
	Window();
	void SetWindow(unsigned int width, unsigned int height, sf::String title);
	void StartDrawing();
	void EndDrawing();
	bool isClosed();
	void EventControl();
	void Draw(sf::Drawable& shape);
	sf::RenderWindow& getWindow();
	void AddMember(WindowInterface* newMember);
private:
	sf::RenderWindow m_sfmlWindow;
	std::vector<WindowInterface*> m_memberList;
};