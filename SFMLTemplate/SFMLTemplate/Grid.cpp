#include "Grid.h"

void Grid::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
}

void Grid::init()
{
	m_shape.setSize(sf::Vector2f(200, 200));
	m_shape.setFillColor(sf::Color::Transparent);
	m_shape.setOutlineColor(sf::Color::Black);
	m_shape.setOutlineThickness(3);

}
