#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Sapling
{
public:
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& win) = 0;
	virtual void init() = 0;
	virtual void setPosition(sf::Vector2f loc) = 0;
private:

};

