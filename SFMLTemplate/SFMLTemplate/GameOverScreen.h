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
	sf::CircleShape m_shadow[5];
	sf::Font m_font;
	sf::Text m_text;
	bool restart = false;

	sf::Sprite sprite[5];
	sf::Texture text1;
	sf::Texture text2;
	sf::Texture text3;
	sf::Texture text4;
	sf::Texture text5;
};

