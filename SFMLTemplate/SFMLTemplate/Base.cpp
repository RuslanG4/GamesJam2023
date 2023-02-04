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

void Base::setType(Type t_type)
{
	m_type = t_type; 
	switch (m_type)
	{
	case Type::FIGHTER:
		health = 110;
		damage = 30;
		hitChance = 75;
		break;
	case Type::ARCHER:
		health = 90;
		damage = 25;
		hitChance = 80;
		break;

	}
}

void Base::takeDamage(int t_damage)
{
	health -= damage;
}

void Base::attack(Enemy& t_enemy)
{
	t_enemy.takeDamage(damage);
	hasAttacked = true;
}
