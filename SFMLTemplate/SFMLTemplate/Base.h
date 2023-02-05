#pragma once
#include"Sapling.h"

class Base : public Sapling
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init();
	void setPosition(sf::Vector2f loc) { m_sprite.setPosition(loc); };
	Type getType() { return m_type; }
	void setType(Type t_type) ;
	sf::Vector2f getPos() { return m_sprite.getPosition(); };
	void takeDamage(int t_damage);
	void attack(Enemy& t_enemy);
	bool getAttack() { return hasAttacked; };

	void setGridNumber(int t_number) { gridNum = t_number; };
	int checkGridNumber() { return gridNum; };
	int getHealth() { return health; };
	void resetAttacks() { hasAttacked = false; }
	int getDamgage() { return damage; };
	void heal(Sapling& t_sap);
	void getHeal();
	void kill() {isDead = true;}
	bool getAlive() { return isDead; };
	void setAttacked() { hasAttacked = true; };

private:
	sf::Sprite m_sprite;
	sf::Texture m_textureRanged;
	sf::Texture m_texture;

	Type m_type = Type::NONE;
	bool hasAttacked = false;
	int health = 20;
	int maxHealth;
	int damage = 20;
	int hitChance;
	int gridNum;
	int damageTimer = 0;
	bool isDead = false;

};

