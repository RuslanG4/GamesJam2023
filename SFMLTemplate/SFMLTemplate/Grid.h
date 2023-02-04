#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Grid
{
public:
	Grid() { init(); };
	void render(sf::RenderWindow& win);
	void init();
	void setPosition(sf::Vector2f loc) { m_shape.setPosition(loc); };
	sf::Vector2f getPos() { return m_shape.getPosition(); };
	void setOccupied() { occupied = true; };
	bool checkOccupied() { return occupied; };
private:
	sf::RectangleShape m_shape;
	bool occupied = false;
};

