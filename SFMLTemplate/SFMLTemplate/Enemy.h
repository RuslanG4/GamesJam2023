#pragma once

#include"ClassType.h"
#include <SFML/Graphics.hpp>
#include<iostream>

class Sapling;

class Enemy
{
public:
	/// <summary>
	/// Updates any enemy functions
	/// </summary>
	virtual void update() = 0;
	/// <summary>
	/// draws to screen
	/// </summary>
	/// <param name="win"></param>
	virtual void render(sf::RenderWindow& win) = 0;
	/// <summary>
	/// initialises sprites
	/// </summary>
	virtual void init() = 0;
	/// <summary>
	/// sets position of sprites
	/// </summary>
	/// <param name="loc"></param>
	virtual void setPosition(sf::Vector2f loc) = 0;
	/// <summary>
	/// checks what type enemy is
	/// </summary>
	/// <returns></returns>
	virtual Type getType() = 0;
	/// <summary>
	/// sets the type of the enemy
	/// </summary>
	/// <param name="t_type"></param>
	virtual void setType(Type t_type) = 0;
	/// <summary>
	/// gets the position of the enemy
	/// </summary>
	/// <returns></returns>
	virtual sf::Vector2f getPos() = 0;

	/// <summary>
	/// takes damage, decreases health value based on taken in damage
	/// </summary>
	/// <param name="t_damage"></param>
	virtual void takeDamage(int t_damage)=0;
	/// <summary>
	/// returns health value
	/// </summary>
	/// <returns></returns>
	virtual int getHealth() = 0;
	/// <summary>
	/// returns amount of damage enemy can deal
	/// </summary>
	/// <returns></returns>
	virtual int getDamage() = 0;
	/// <summary>
	/// checks if enemy is alive
	/// </summary>
	/// <returns></returns>
	virtual bool checkDead() = 0;
	/// <summary>
	/// kills enemy
	/// </summary>
	virtual void kill() = 0;

private:

};

#include"Sapling.h"