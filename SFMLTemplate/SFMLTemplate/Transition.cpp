#include "Transition.h"

void Transition::update()
{
}

void Transition::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
	win.draw(m_text);
}

void Transition::init(sf::Font& font)
{
	m_font = font;
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(40U);
	m_text.setPosition(550, 820);
	m_text.setString("enemies defeated transition screen");

	m_shape.setFillColor(sf::Color::Black);
	m_shape.setPosition(400, 750);
	m_shape.setSize(sf::Vector2f(1120, 200));
}
