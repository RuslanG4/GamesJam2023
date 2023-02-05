#include "RangedEnemy.h"

void RangedEnemy::update()
{
}

void RangedEnemy::render(sf::RenderWindow& win)
{
	win.draw(m_sprite);
}

void RangedEnemy::init()
{
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setOrigin(16, 16);

	if (!m_text.loadFromFile("ASSETS\\IMAGES\\Rabbit_Fire_Canon.png"))
	{
		std::cout << "error loading rabbit";
	}
	m_sprite.setTexture(m_text);
	m_sprite.setOrigin(16, 16);
	m_sprite.setScale(5, 5);
}

void RangedEnemy::takeDamage(int t_damage)
{
	health -= t_damage;
	if (health <= 0)
	{
		health = 0;
	}
}


