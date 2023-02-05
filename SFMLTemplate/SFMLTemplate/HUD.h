#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
class HUD
{
public:
	void update();
	void render(sf::RenderWindow& win);
	void init(sf::Font& font);
	void getAction(int t_num, int t_num2, int num3);
	void getEnemyAction(int t_num, int t_num2, int num3);
	void moveAction(int t_num, int t_num2);
	void endTurn();
	void startTurn();

private:
	sf::RectangleShape m_shape;
	sf::Font m_font;
	sf::Text m_text;

	sf::Texture text;
	sf::Sprite sprite;

};

