#pragma once
#include"ClassType.h"
#include"Enemy.h"
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
	virtual void attack(Enemy& t_enemy)=0;
private:

};

