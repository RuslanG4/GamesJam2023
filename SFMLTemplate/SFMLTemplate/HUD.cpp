#include "HUD.h"

void HUD::update()
{

}

void HUD::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
	win.draw(m_text);
	win.draw(sprite);
}

void HUD::init(sf::Font& font)
{
	m_font = font;
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(40U);
	m_text.setPosition(520, 820);

	m_shape.setFillColor(sf::Color::Black);
	m_shape.setPosition(400, 750);
	m_shape.setSize(sf::Vector2f(1120, 200));

	if (!text.loadFromFile("ASSETS\\IMAGES\\Border.png"))
	{
		std::cout << "error loading border";
	}
	sprite.setTexture(text);
	sprite.setPosition(310, 700);
}

void HUD::getAction(int t_num, int t_num2, int num3)
{
	m_text.setString(" Sapling number " + std::to_string(t_num+1) + " attacks enemy number " + std::to_string(t_num2) + "\n " + 
		std::to_string(num3) + " damage!");
}

void HUD::getEnemyAction(int t_num, int t_num2, int num3)
{
	m_text.setString(" Enemy number " + std::to_string(t_num+1) + " attacks Sapling number " + std::to_string(t_num2 + 1) + "\n "
	+ " dealing " +std::to_string(num3) + " damage!");
}

void HUD::moveAction(int t_num, int t_num2)
{
	m_text.setString(" Sapling number " + std::to_string(t_num) + " moves to grid space " + std::to_string(t_num2+1));
}

void HUD::endTurn()
{
	m_text.setString(" Player ends turn!");
}

void HUD::startTurn()
{
	m_text.setString(" Players turn!");
}
