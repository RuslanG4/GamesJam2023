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

void MeleeEnemy::takeDamage(int t_damage)
{
	health -= t_damage;
	if (health < 50)
	{
		m_shape.setFillColor(sf::Color::Magenta);
	}
}


