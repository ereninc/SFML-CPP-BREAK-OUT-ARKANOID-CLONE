#pragma once
#include<SFML/Window/Event.hpp>
#include "EventHandler.hpp"

class WindowInterface
{
public:
	virtual void MouseMove(int x, int y) = 0;;
	virtual void MouseOnEnable(sf::Event::MouseButtonEvent btnEvent);
	virtual void MouseOnDisable(sf::Event::MouseButtonEvent btnEvent) = 0;
	virtual bool isOn(int x, int y) = 0;
	virtual void isNotOn() = 0;
	
	void AddFunction(funcCalled func);
protected:
	funcList m_funcList;
};
