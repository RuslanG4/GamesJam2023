#include "Grid.h"

void Grid::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
	win.draw(m_text);
}

void Grid::init(sf::Font& font)
{
	m_shape.setSize(sf::Vector2f(200, 200));
	m_shape.setFillColor(sf::Color::Transparent);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(3);

	m_font = font;
	m_text.setFont(m_font);
	m_text.setCharacterSize(40U);
}

void Grid::writeHealth(int enemy)
{
	m_text.setPosition(m_shape.getPosition().x + 5, m_shape.getPosition().y );
	int health = enemy;
	m_text.setString(std::to_string(health));
}
