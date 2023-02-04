#pragma once
#include"Enemy.h"

//hardwood
class MeleeEnemy : public Enemy
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init();
	void setPosition(sf::Vector2f loc) { m_shape.setPosition(loc); };
	Type getType() { return m_type; }
	void setType(Type t_type) { m_type = t_type; };
	sf::Vector2f getPos() { return m_shape.getPosition(); };

	void takeDamage(int t_damage);
	int getHealth() { return health; };
	void attack();
private:
	sf::RectangleShape m_shape{ sf::Vector2f(32,32) };
	Type m_type = Type::NONE;
	int health = 110;
	int damage = 25;
	int hitChance = 75;

};

