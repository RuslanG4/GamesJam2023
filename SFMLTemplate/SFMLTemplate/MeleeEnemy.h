#pragma once

#include"Enemy.h"

//hardwood
class MeleeEnemy : public Enemy
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init();
	void setPosition(sf::Vector2f loc) { m_sprite.setPosition(loc); };
	Type getType() { return m_type; }
	void setType(Type t_type) { m_type = t_type; };
	sf::Vector2f getPos() { return m_sprite.getPosition(); };

	void takeDamage(int t_damage);
	int getHealth() { return health; };
	int getDamage() { return damage; };

	bool checkDead() { return isDead; };

	void kill() { isDead = true; }
private:
	sf::RectangleShape m_shape{ sf::Vector2f(32,32) };

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Texture m_deadTexture;

	bool isDead = false;
	Type m_type = Type::NONE;
	int health = 110;
	int damage = 25;
	int hitChance = 75;
	bool hasAttacked = false;

};

