#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class GameOverScreen
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init(sf::Font& font);
	bool getRestart() { return restart; };

private:
	sf::RectangleShape m_shape;
	sf::Font m_font;
	sf::Text m_text;
	bool restart = false;
};

