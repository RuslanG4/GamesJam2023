#include "RangedEnemy.h"

void RangedEnemy::update()
{
}

void RangedEnemy::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
}

void RangedEnemy::init()
{
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setOrigin(16, 16);
}

void RangedEnemy::takeDamage(int t_damage)
{
	health -= t_damage;
	if (health < 50)
	{
		m_shape.setFillColor(sf::Color::Magenta);
	}
}
