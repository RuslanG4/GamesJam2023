#include "Base.h"

void Base::update()
{
}

void Base::render(sf::RenderWindow& win)
{
	
	win.draw(m_sprite);
}

void Base::init()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\redMapleIdel.png"))
	{
		std::cout << "error loading red maple";
	}
	if (!m_textureRanged.loadFromFile("ASSETS\\IMAGES\\Cedarion.png"))
	{
		std::cout << "error loading cedarion";
	}
	m_sprite.setOrigin(16, 16);
	m_sprite.setScale(5, 5);
	
}

void Base::setType(Type t_type)
{
	m_type = t_type; 
	switch (m_type)
	{
	case Type::FIGHTER:
		m_sprite.setTexture(m_texture);
		health = 110;
		damage = 30;
		hitChance = 75;
		break;
	case Type::ARCHER:
		m_sprite.setTexture(m_textureRanged);
		health = 90;
		damage = 25;
		hitChance = 80;
		break;

	}
}

void Base::takeDamage(int t_damage)
{
	health -= t_damage;
}

void Base::attack(Enemy& t_enemy)
{
	t_enemy.takeDamage(damage);
	hasAttacked = true;
}
