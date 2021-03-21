#pragma once
#include<SFML/Window/Event.hpp>
class WindowInterface
{
public:
	virtual void MouseMove(int x, int y) = 0;;
	virtual void MouseOnEnable(sf::Event::MouseButtonEvent btnEvent) = 0;
	virtual void MouseOnDisable(sf::Event::MouseButtonEvent btnEvent) = 0;
	virtual bool isOn(int x, int y) = 0;
	virtual void isNotOn() = 0;
private:
};
