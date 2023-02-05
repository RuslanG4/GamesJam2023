#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Transition
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init(sf::Font& font);
	bool getRestart() { return restart; };
	void resetRestart() { restart=false; };

private:
	sf::RectangleShape m_shape;
	sf::Font m_font;
	sf::Text m_text;
	bool restart=false;
};

