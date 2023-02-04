#include "MeleeEnemy.h"

void MeleeEnemy::update()
{
}

void MeleeEnemy::render(sf::RenderWindow& win)
{
	//win.draw(m_shape);
	win.draw(m_sprite);
}

void MeleeEnemy::init()
{
	/*m_shape.setFillColor(sf::Color::Red);
	m_shape.setOrigin(16, 16);*/

	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\redMapleIdel.png"))
	{
		std::cout << "error loading red maple";
	}

	if (!m_deadTexture.loadFromFile("ASSETS\\IMAGES\\deadRip.png"))
	{
		std::cout << "error loading dead rip";
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(16, 16);
	m_sprite.setScale(5, 5);
}

void MeleeEnemy::takeDamage(int t_damage)
{
	health -= t_damage;
	if (health <= 0)
	{
		health = 0;
	}
}


