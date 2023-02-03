#pragma once
#include"Sapling.h"

class Base : public Sapling
{
public:
	Base() { init(); };
	void update();
	void render(sf::RenderWindow& win);
	void init();
	void setPosition(sf::Vector2f loc) { m_shape.setPosition(loc); };
private:
	sf::RectangleShape m_shape{ sf::Vector2f(32,32) };

};

