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
#include"Grid.h"
#include"TurnState.h"
#include"HUD.h"
#include"GameOverScreen.h"
#include"Transition.h"

const int MAX_SPROUTS = 6;
const int MAX_ENEMIES = 6;

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

	//moves at start of battle
	void movingSprite();
	bool hasMoved = false;

	void checkBounds();

	bool m_exitGame; // control exiting game

	sf::RenderWindow m_window; // main SFML window

	void setupFont();
	sf::Font m_arialFont;
	sf::Text m_text;
	sf::Text m_enemyText;

	Grid myGrid[6];
	Grid enemyGrid[6];

	HUD myHud;
	GameOverScreen gameOverScreen;
	Transition myTransitionScreen;

	sf::RectangleShape m_selectionSapling;
	sf::RectangleShape m_selectionEnemy;
	sf::RectangleShape m_selectionHeal;
	sf::Vector2f offScreenPos{ -300,-300 };

	//SPRITES
	sf::Sprite m_attackSprite;
	sf::Texture m_attackTexture;
	sf::Sprite m_healSprite;
	sf::Texture m_healTexture;
	sf::Sprite m_buffSprite;
	sf::Texture m_buffTexture;
	sf::Sprite m_debuffSprite;
	sf::Texture m_debuffTexture;
	sf::Sprite m_turnOverSprite;
	sf::Texture m_turnOverTexture;
	void setUpSprites();

	//checks players attack
	bool pressedAttack = false;
	void attack();

	//spalings
	int currentSaplings = 3;
	Sapling *sapling[MAX_SPROUTS];
	void createRoots();

	//selections made by player
	int selectedSapling = 0;
	int enemySelected = 0;
	int healSelection = 0;

	//mouse presses
	bool pressedBox = false;
	bool heldMouse = false;

	/// <summary>
	/// friendly grid positions
	/// </summary>
	sf::Vector2f positions[6]
	{
		{200,100},
		{400,100},
		{200,300},
		{400,300},
		{200,500},
		{400,500}
	};

	//enemy grid positions
	sf::Vector2f ePositions[6]
	{
		{1320,100},
		{1520,100},
		{1320,300},
		{1520,300},
		{1320,500},
		{1520,500}
	};

	//gamestate
	GameState m_gamestate = GameState::PLAYERTURN;

	void checkGrids();

	//Enemy varialbes
	int randomPos = 0;
	int currentEnemies = 3;
	Enemy* enemy[MAX_ENEMIES];

	void createEnemies();
	void enemyMove();
	void enemyAttack();
	void enemyHeal();
	int attackingEnemy = 3;
	int enemyMoveTimer = 0;
	int randomEnemyNumber = 0;
	int numOfDeadEnemies = 0;

	void killEnemy();
	void killSaplings();

	//hover for icons
	void mousePos();

	//spawning jumping letter
	bool startLetter = false;
	bool hasSpawned = false;
	sf::Vector2f textVelocity;
	void damageNumberAnimate();

	//spawing enemy jumping letters
	bool enemyStartLetter = false;
	bool enemyLetterSpawned = false;
	sf::Vector2f enemyTextVelocity;
	void enemyNumbersAnimate();

	//checking for gameover
	int numOfDeadSaplings = 0;
	void checkGameOver();
	void checkGameWin();

	void deleteEntites();
	void resetVars();

};

#endif // !GAME_HPP



