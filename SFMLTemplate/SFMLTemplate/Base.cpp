#include "Base.h"

void Base::update()
{
}

void Base::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
}

void Base::init()
{
	m_shape.setFillColor(sf::Color::Blue);
	m_shape.setOrigin(16, 16);
}
