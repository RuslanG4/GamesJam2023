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
	m_text.setCharacterSize(140U);
	m_text.setPosition(300, 120);
	m_text.setString("Enemies Defeated!");

	m_shape.setFillColor(sf::Color(0, 0, 0, 132));
	m_shape.setPosition(220, 100);
	m_shape.setSize(sf::Vector2f(1520, 400));
}
