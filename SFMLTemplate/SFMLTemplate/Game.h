/// <summary>
/// Ruslan Gavrilov
/// February 2022
///
/// 
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Sapling.h"
#include"Base.h"
#include"GameState.h"
#include"Enemy.h"
#include"RangedEnemy.h"
#include"MeleeEnemy.h"

const int MAX_SPROUTS = 6;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouse(sf::Event t_event);
	void processMouseRelease(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void setupFontAndText();

	bool m_exitGame; // control exiting game

	sf::RenderWindow m_window; // main SFML window

	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_topScore;

	sf::RectangleShape m_grid[6];

	sf::RectangleShape m_eGrid[6];

	int currentSaplings = 3;

	Sapling *sapling;

<<<<<<< HEAD
	Enemy* enemy;
=======
	bool fBox1 = false;
>>>>>>> bef3d3f69df5dfdcbaf2ea6feae019ccda63d31e

	sf::Vector2f positions[6]
	{
		{200,100},
		{400,100},
		{200,300},
		{400,300},
		{200,500},
		{400,500}
	};

	sf::Vector2f ePositions[6]
	{
		{1320,100},
		{1520,100},
		{1320,300},
		{1520,300},
		{1320,500},
		{1520,500}
	};

	GameState m_gamestate = GameState::PLAYERTURN;

	void setType();
	
	void createEnemies();

};

#endif // !GAME_HPP



