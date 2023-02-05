#pragma once

#include"Enemy.h"

//hardwood
class MeleeEnemy : public Enemy
{
public:
	void update(); //update any enemy funciton
	void render(sf::RenderWindow& win); //draws to screen
	void init(); //initialisation
	void setPosition(sf::Vector2f loc) { m_sprite.setPosition(loc); }; //sets position of sprite


	//GETTERS
	sf::Vector2f getPos() { return m_sprite.getPosition(); };
	Type getType() { return m_type; } //gets type pf player
	bool checkDead() { return isDead; };
	int getHealth() { return health; };
	int getDamage() { return damage; };
	//SETTERS
	void kill() { isDead = true; }
	void setType(Type t_type) { m_type = t_type; }; //sets type on player

	//TAKING DAMAGE
	void takeDamage(int t_damage);
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

