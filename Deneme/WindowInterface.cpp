#include "WindowInterface.hpp"

void WindowInterface::MouseOnEnable(sf::Event::MouseButtonEvent btnEvent)
{
	for (auto next: m_funcList)
	{
		next();
	}
}

void WindowInterface::AddFunction(funcCalled func)
{
	m_funcList.push_back(func);
}