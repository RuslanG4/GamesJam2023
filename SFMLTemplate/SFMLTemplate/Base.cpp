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
	if (m_type == Type::FIGHTER)
	{
		health = 110;
		damage = 15;
	}
	if (m_type == Type::ARCHER)
	{
		health = 90;
		damage = 20;
	}
}

void Base::attack(Enemy& t_enemy)
{
	t_enemy.takeDamage(damage);
	//hasAttacked = true;
}

void Base::takeDamage(int t_damage)
{
	health -= damage;
}
