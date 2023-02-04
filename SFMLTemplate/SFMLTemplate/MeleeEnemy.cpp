#include "MeleeEnemy.h"

void MeleeEnemy::update()
{
}

void MeleeEnemy::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
}

void MeleeEnemy::init()
{
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setOrigin(16, 16);
}
