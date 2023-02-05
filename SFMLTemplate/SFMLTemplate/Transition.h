#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Transition
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init(sf::Font& font);

private:
	sf::RectangleShape m_shape;
	sf::Font m_font;
	sf::Text m_text;
};

