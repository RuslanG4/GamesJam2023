#pragma once

#include"ClassType.h"
#include <SFML/Graphics.hpp>
#include<iostream>

class Sapling;

class Enemy
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
	virtual int getHealth() = 0;
	virtual int getDamage() = 0;

	virtual bool checkAttacked() = 0;
	virtual void setAttacked() = 0;
	virtual void setUnAttacked() = 0;

private:

};

#include"Sapling.h"