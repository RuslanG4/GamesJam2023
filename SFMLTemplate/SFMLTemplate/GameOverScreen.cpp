#include "GameOverScreen.h"

void GameOverScreen::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		restart = true;
	}
}

void GameOverScreen::render(sf::RenderWindow& win)
{
	win.draw(m_shape);
	win.draw(m_text);
	//for (int i = 0; i < 5; i++)
	//{
	//	win.draw(m_shadow[i]);
	//}
	win.draw(sprite[0]);
	win.draw(sprite[1]);
	win.draw(sprite[2]);
	win.draw(sprite[3]);
	win.draw(sprite[4]);

}

void GameOverScreen::init(sf::Font& font)
{
	m_font = font;
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(140U);
	m_text.setPosition(250, 120);
	m_text.setString("        GAMEOVER \n PRESS R TO RESTART");

	m_shape.setFillColor(sf::Color(0,0,0,132));
	m_shape.setPosition(220, 100);
	m_shape.setSize(sf::Vector2f(1520, 400));
	for (int i = 0; i < 5; i++)
	{
		//m_shadow[i].setSize(sf::Vector2f(150, 64));
		m_shadow[i].setRadius(65);
		m_shadow[i].setFillColor(sf::Color(0, 0, 0, 132));
	}
	//m_shadow[0].setPosition(305, 740);

	if (!text1.loadFromFile("ASSETS\\IMAGES\\Ashbringer_Lined.png"))
	{
		std::cout << "error loading ashvringer";
	}
	sprite[0].setTexture(text1);
	sprite[0].setPosition(300, 650);
	sprite[0].setScale(5, 5);


	if (!text2.loadFromFile("ASSETS\\IMAGES\\Willow_Wisp_Lined.png"))
	{
		std::cout << "error loading ashvringer";
	}
	sprite[1].setTexture(text2);
	sprite[1].setPosition(600, 750);
	sprite[1].setScale(5, 5);


	if (!text3.loadFromFile("ASSETS\\IMAGES\\Sugar_Pine_Lined.png"))
	{
		std::cout << "error loading ashvringer";
	}
	sprite[2].setTexture(text3);
	sprite[2].setPosition(900, 650);
	sprite[2].setScale(5, 5);

	if (!text4.loadFromFile("ASSETS\\IMAGES\\Cypressor_Lined.png"))
	{
		std::cout << "error loading ashvringer";
	}
	sprite[3].setTexture(text4);
	sprite[3].setPosition(1200, 750);
	sprite[3].setScale(5, 5);

	if (!text5.loadFromFile("ASSETS\\IMAGES\\Zapling_Lined.png"))
	{
		std::cout << "error loading ashvringer";
	}
	sprite[4].setTexture(text5);
	sprite[4].setPosition(1500, 650);
	sprite[4].setScale(5, 5);
}
