#pragma once
#include"ClassType.h"
#include"MeleeEnemy.h"
#include <SFML/Graphics.hpp>
#include<iostream>


class Sapling
{
public:
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& win) = 0;
	virtual void init() = 0;
	virtual void setPosition(sf::Vector2f loc) = 0;
	virtual Type getType() = 0;
	virtual void setType(Type t_type) = 0;
	virtual sf::Vector2f getPos() = 0;
	virtual void takeDamage(int t_damage)=0;
	virtual void attack(Enemy& t_enemy) = 0;
	virtual bool getAttack() = 0;
	virtual void setGridNumber(int t_number) = 0;
	virtual int checkGridNumber() = 0;
	virtual int getHealth() = 0;
	virtual void resetAttacks() = 0;
	virtual int getDamgage() = 0;
	virtual void heal(Sapling& t_sap) = 0;
	virtual void getHeal() = 0;
	virtual void kill()=0;
	virtual bool getAlive() = 0;
private:

};

