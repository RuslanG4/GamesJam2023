#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Enemy.h"

class Grid
{
public:
	void render(sf::RenderWindow& win);
	void init(sf::Font &font);
	void setPosition(sf::Vector2f loc) { m_shape.setPosition(loc); };
	sf::Vector2f getPos() { return m_shape.getPosition(); };
	void setOccupied() { occupied = true; };
	void setUnOccupied() { occupied = false; };
	bool checkOccupied() { return occupied; };
	void setEnemyNumber(int t_number) { enemyNumber = t_number; };
	int enemyNumberCheck() { return enemyNumber; };
	void writeHealth(int enemy);
	void boxSelected(){ m_shape.setOutlineColor(sf::Color::Red); }
	void boxDeSelected() { m_shape.setOutlineColor(sf::Color::Black); }
private:
	sf::RectangleShape m_shape;
	bool occupied = false;
	int enemyNumber = 8;
	sf::Font m_font;
	sf::Text m_text;
};

