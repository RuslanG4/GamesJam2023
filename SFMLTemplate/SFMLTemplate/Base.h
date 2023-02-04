#pragma once
#include"Sapling.h"

class Base : public Sapling
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init();
	void setPosition(sf::Vector2f loc) { m_shape.setPosition(loc); };
	Type getType() { return m_type; }
	void setType(Type t_type) ;
	sf::Vector2f getPos() { return m_shape.getPosition(); };
	void takeDamage(int t_damage);
	void attack(Enemy& t_enemy);
	bool getAttack() { return hasAttacked; };

	void setGridNumber(int t_number) { gridNum = t_number; };
	int checkGridNumber() { return gridNum; };
	int getHealth() { return health; };

private:
	sf::RectangleShape m_shape{ sf::Vector2f(32,32) };
	Type m_type = Type::NONE;
	bool hasAttacked = false;
	int health = 20;
	int damage = 20;
	int hitChance;
	int gridNum;

};

