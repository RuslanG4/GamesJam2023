#include "Game.h"

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1920U, 1080U, 32U }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
	setUpSprites();
	setupFont();
	createRoots();
	createEnemies();
	setupFontAndText();

}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}

/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonPressed == newEvent.type) //user pressed mouse
		{
			processMouse(newEvent);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type) //user pressed mouse
		{
			processMouseRelease(newEvent);
		}
	}
}
/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

}

void Game::processMouse(sf::Event t_event)
{
	const int F_COL_LEFT = 200;
	const int F_COL_RIGHT = 400;
	const int F_ROW_TOP = 100;
	const int F_ROW_BOTTOM = 300;

	const int E_COL_LEFT = 1320;
	const int E_COL_RIGHT = 1520;
	const int E_ROW_TOP = 100;
	const int E_ROW_BOTTOM = 300;

	//Friendly
	//Friendly archers Coloum 1 & process rows 
	if (t_event.mouseButton.x > F_COL_LEFT && t_event.mouseButton.x < F_COL_RIGHT)
	{
		if (t_event.mouseButton.y > F_ROW_TOP && t_event.mouseButton.y < F_ROW_BOTTOM)
		{
			std::cout << "Pressed friendly archer 1 box" << std::endl;

			if (myGrid[0].checkOccupied())
			{
				selectedSapling = myGrid[0].enemyNumberCheck();
				myGrid[0].setEnemyNumber(selectedSapling);
				m_selectionSapling.setPosition(positions[0]);
			}


			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed friendly archer 2 box" << std::endl;
			if (myGrid[2].checkOccupied())
			{
				selectedSapling = myGrid[2].enemyNumberCheck();
				myGrid[2].setEnemyNumber(selectedSapling);
				m_selectionSapling.setPosition(positions[2]);
			}
			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed friendly archer 3 box" << std::endl;
			if (myGrid[4].checkOccupied())
			{
				selectedSapling = myGrid[4].enemyNumberCheck();
				myGrid[4].setEnemyNumber(selectedSapling);
				m_selectionSapling.setPosition(positions[4]);
			}
			pressedBox = true;
			heldMouse = true;

		}
	}
	//Friendly Fighters Coloum 2 & process rows
	if (t_event.mouseButton.x > F_COL_LEFT + 200 && t_event.mouseButton.x < F_COL_RIGHT + 200)
	{
		if (t_event.mouseButton.y > F_ROW_TOP && t_event.mouseButton.y < F_ROW_BOTTOM)
		{
			std::cout << "Pressed friendly fighters 1 box" << std::endl;
			if (myGrid[1].checkOccupied())
			{
				selectedSapling = myGrid[1].enemyNumberCheck();
				myGrid[1].setEnemyNumber(selectedSapling);
				m_selectionSapling.setPosition(positions[1]);
			}

			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed friendly fighters 2 box" << std::endl;
			if (myGrid[3].checkOccupied())
			{
				selectedSapling = myGrid[3].enemyNumberCheck();
				myGrid[3].setEnemyNumber(selectedSapling);
				m_selectionSapling.setPosition(positions[3]);

			}
			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed friendly fighters 3 box" << std::endl;
			if (myGrid[5].checkOccupied())
			{
				selectedSapling = myGrid[5].enemyNumberCheck();
				myGrid[5].setEnemyNumber(selectedSapling);
				m_selectionSapling.setPosition(positions[5]);
			}

			pressedBox = true;
			heldMouse = true;

		}
	}


	//Enemy boxes
	//Enemy Fighters Coloum 1 & process rows
	if (t_event.mouseButton.x > E_COL_LEFT && t_event.mouseButton.x < E_COL_RIGHT)
	{
		if (t_event.mouseButton.y > E_ROW_TOP && t_event.mouseButton.y < F_ROW_BOTTOM)
		{
			std::cout << "Pressed Enemy fighter 1 box" << std::endl;
			enemySelected = enemyGrid[0].enemyNumberCheck();
			m_selectionEnemy.setPosition(ePositions[0]);
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed Enemy fighter 2 box" << std::endl;
			enemySelected = enemyGrid[2].enemyNumberCheck();
			m_selectionEnemy.setPosition(ePositions[2]);
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed Enemy fighter 3 box" << std::endl;
			enemySelected = enemyGrid[4].enemyNumberCheck();
			m_selectionEnemy.setPosition(ePositions[4]);
			pressedBox = true;
		}

	}
	//Enemy Archers Coloum 2 & process rows
	if (t_event.mouseButton.x > E_COL_LEFT +200 && t_event.mouseButton.x < E_COL_RIGHT+200)
	{
		if (t_event.mouseButton.y > E_ROW_TOP && t_event.mouseButton.y < F_ROW_BOTTOM)
		{
			std::cout << "Pressed Enemy archer 1 box" << std::endl;
			enemySelected = enemyGrid[1].enemyNumberCheck();
			m_selectionEnemy.setPosition(ePositions[1]);
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed Enemy archer 2 box" << std::endl;
			enemySelected = enemyGrid[3].enemyNumberCheck();
			m_selectionEnemy.setPosition(ePositions[3]);
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed Enemy archer 3 box" << std::endl;
			enemySelected = enemyGrid[5].enemyNumberCheck();
			m_selectionEnemy.setPosition(ePositions[5]);
			pressedBox = true;
		}

	}

}

void Game::processMouseRelease(sf::Event t_event)
{
	const int ATTACK_TOP = 200;
	const int ATTACK_BOTTOM = 280;
	const int ATTACK_LEFT = 900;
	const int ATTACK_RIGHT = 1000;


	heldMouse = false;
	std::cout << "enemy selected : " + std::to_string(enemySelected);
	std::cout << "player selected : " + std::to_string(selectedSapling);

	if (t_event.mouseButton.x > ATTACK_LEFT && t_event.mouseButton.x < ATTACK_RIGHT)
	{
		if (t_event.mouseButton.y > ATTACK_TOP && t_event.mouseButton.y < ATTACK_BOTTOM)
		{
			std::cout << "Attack" << std::endl;
			if (!sapling[selectedSapling]->getAttack())
			{
				m_text.setPosition(m_selectionEnemy.getPosition().x + 100, m_selectionEnemy.getPosition().y + 100);
			}
			attack();
			startLetter = true;
			hasMoved = true;
			
		}
	}
	if (t_event.mouseButton.x > 800 && t_event.mouseButton.x < 880)
	{
		if (t_event.mouseButton.y > 400 && t_event.mouseButton.y < 480)
		{
			myHud.endTurn();
			m_gamestate = GameState::ENEMYTURN;
			attackingEnemy = currentEnemies - 1;//currentEnemies;
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	if (m_gamestate == GameState::PLAYERTURN)
	{
		mousePos();
		checkGrids();
		checkBounds();
		if (heldMouse && !hasMoved)
		{
			movingSprite();
		}
		for (int i = 0; i < 6; i++)
		{
			if (enemyGrid[i].checkOccupied())
			{
				enemyGrid[i].writeHealth(enemy[enemyGrid[i].enemyNumberCheck()]->getHealth());
			}
			if (myGrid[i].checkOccupied())
			{
				myGrid[i].writeHealth(sapling[myGrid[i].enemyNumberCheck()]->getHealth());
			}
			if (!myGrid[i].checkOccupied())
			{
				myGrid[i].writeHealth(0);
			}
		}
		killEnemy();
		if (startLetter)
		{
			damageNumberAnimate();
		}
	}
	
	if (m_gamestate == GameState::ENEMYTURN)
	{
		enemyMove();
		for (int i = 0; i < 6; i++)
		{
			if (enemyGrid[i].checkOccupied())
			{
				enemyGrid[i].writeHealth(enemy[enemyGrid[i].enemyNumberCheck()]->getHealth());
			}
			if (myGrid[i].checkOccupied())
			{
				myGrid[i].writeHealth(sapling[myGrid[i].enemyNumberCheck()]->getHealth());
			}
			if (!myGrid[i].checkOccupied())
			{
				myGrid[i].writeHealth(0);
			}
		}
		if (enemyStartLetter)
		{
			enemyNumbersAnimate();
		}
		killSaplings();
	}
	for (int i = 0; i < currentEnemies; i++)
	{
		if (enemy[i]->checkDead())
		{
			enemy[i]->setPosition(offScreenPos);
		}
	}
	for (int i = 0; i < currentSaplings; i++)
	{
		if (sapling[i]->getAlive())
		{
			sapling[i]->setPosition(offScreenPos);
		}
	}


	checkGameOver();
	checkGameWin();

	if (m_gamestate == GameState::GAMEOVER)
	{
		gameOverScreen.update();
		if (gameOverScreen.getRestart())
		{
			deleteEntites();
			resetVars();
			createEnemies();
			createRoots();
			m_gamestate = GameState::PLAYERTURN;
		}
	}

	if (m_gamestate == GameState::TRANSITION)
	{
		myTransitionScreen.update();
	}
}
/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Green);

	if (m_gamestate == GameState::PLAYERTURN || m_gamestate == GameState::ENEMYTURN)
	{
		for (int i = 0; i < currentEnemies; i++)
		{
			enemy[i]->render(m_window);
		}

		for (int i = 0; i < 6; i++)
		{
			myGrid[i].render(m_window);
			enemyGrid[i].render(m_window);
		}
		for (int i = 0; i < currentSaplings; i++)
		{
			sapling[i]->render(m_window);
		}
		m_window.draw(m_attackSprite);
		m_window.draw(m_healSprite);
		m_window.draw(m_buffSprite);
		m_window.draw(m_debuffSprite);
		m_window.draw(m_turnOverSprite);
		myHud.render(m_window);
		m_window.draw(m_selectionSapling);
		m_window.draw(m_selectionEnemy);
		m_window.draw(m_selectionHeal);

		m_window.draw(m_text);
		m_window.draw(m_enemyText);
	}
	if (m_gamestate == GameState::GAMEOVER)
	{
		gameOverScreen.render(m_window);
	}
	if (m_gamestate == GameState::TRANSITION)
	{
		myTransitionScreen.render(m_window);
	}
	m_window.display();
}
/// <summary>
/// sets up text and grids
/// </summary>
void Game::setupFontAndText()
{
	attackingEnemy = currentEnemies;
	for (int i = 0; i < 6 ; i++)
	{
		myGrid[i].setPosition(positions[i]);
		myGrid[i].init(m_arialFont);
		enemyGrid[i].setPosition(ePositions[i]);
		enemyGrid[i].init(m_arialFont);
	}

	myHud.init(m_arialFont);
	gameOverScreen.init(m_arialFont);
	myTransitionScreen.init(m_arialFont);

	m_selectionEnemy.setSize(sf::Vector2f(200, 200));
	m_selectionEnemy.setOutlineColor(sf::Color::Red);
	m_selectionEnemy.setOutlineThickness(5);
	m_selectionEnemy.setFillColor(sf::Color::Transparent);
	m_selectionEnemy.setPosition(offScreenPos);

	m_selectionSapling.setSize(sf::Vector2f(200, 200));
	m_selectionSapling.setOutlineColor(sf::Color::Red);
	m_selectionSapling.setOutlineThickness(5);
	m_selectionSapling.setFillColor(sf::Color::Transparent);
	m_selectionSapling.setPosition(offScreenPos);

	m_selectionHeal.setSize(sf::Vector2f(200, 200));
	m_selectionHeal.setOutlineColor(sf::Color::Blue);
	m_selectionHeal.setOutlineThickness(5);
	m_selectionHeal.setFillColor(sf::Color::Transparent);
	m_selectionHeal.setPosition(offScreenPos);
}
/// <summary>
/// moves sprties along with mouse pos
/// </summary>
void Game::movingSprite()
{
	sapling[selectedSapling]->setPosition(sf::Vector2f(sf::Mouse::getPosition(m_window)));
}
/// <summary>
/// keeps sprites withing their grids
/// </summary>
void Game::checkBounds()
{

	if (sapling[selectedSapling]->getPos().x > 600 || sapling[selectedSapling]->getPos().x < 200)
	{
		sapling[selectedSapling]->setPosition(sf::Vector2f(positions[sapling[selectedSapling]->checkGridNumber()].x + 100, positions[sapling[selectedSapling]->checkGridNumber()].y + 100));
	}
	if (sapling[selectedSapling]->getPos().y < 100 || sapling[selectedSapling]->getPos().y > 700)
	{
		sapling[selectedSapling]->setPosition(sf::Vector2f(positions[sapling[selectedSapling]->checkGridNumber()].x + 100, positions[sapling[selectedSapling]->checkGridNumber()].y + 100));
	}

	
}
/// <summary>
/// sets up font and string for damage
/// </summary>
void Game::setupFont()
{
	if (!m_arialFont.loadFromFile("ASSETS\\FONTS\\arial.ttf"))
	{
		std::cout << "error loading font";
	}
	m_text.setFont(m_arialFont);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setOutlineThickness(4);
	m_text.setCharacterSize(50U);
	m_text.setPosition(offScreenPos);

	m_enemyText.setFont(m_arialFont);
	m_enemyText.setOutlineColor(sf::Color::Red);
	m_enemyText.setOutlineThickness(4);
	m_enemyText.setCharacterSize(50U);
	m_enemyText.setPosition(offScreenPos);
}
/// <summary>
/// sets up sprites
/// </summary>
void Game::setUpSprites()
{
	//Sprite setups
	if (!m_attackTexture.loadFromFile("ASSETS\\IMAGES\\attack1.png"))
	{
		std::cout << "Couldnt load attack" << std::endl;
	}

	m_attackSprite.setTexture(m_attackTexture);
	m_attackSprite.setPosition(900, 200);
	m_attackSprite.setScale(5, 5);

	if (!m_healTexture.loadFromFile("ASSETS\\IMAGES\\healing.png"))
	{
		std::cout << "Heal not loading" << std::endl;
	}
	m_healSprite.setTexture(m_healTexture);
	m_healSprite.setPosition(800, 200);
	m_healSprite.setScale(5, 5);

	if (!m_buffTexture.loadFromFile("ASSETS\\IMAGES\\buff.png"))
	{
		std::cout << "buff not loading" << std::endl;
	}
	m_buffSprite.setTexture(m_buffTexture);
	m_buffSprite.setPosition(800, 300);
	m_buffSprite.setScale(5, 5);


	if (!m_debuffTexture.loadFromFile("ASSETS\\IMAGES\\debuff.png"))
	{
		std::cout << "buff not loading" << std::endl;
	}
	m_debuffSprite.setTexture(m_debuffTexture);
	m_debuffSprite.setPosition(900, 300);
	m_debuffSprite.setScale(5, 5);

	if (!m_turnOverTexture.loadFromFile("ASSETS\\IMAGES\\endTurn.png"))
	{
		std::cout << "buff not loading" << std::endl;
	}
	m_turnOverSprite.setTexture(m_turnOverTexture);
	m_turnOverSprite.setPosition(800, 400);
	m_turnOverSprite.setScale(5, 5);
}
/// <summary>
/// player attacking enemy function
/// </summary>
void Game::attack()
{
	for (int i = 0; i < currentSaplings; i++)
	{
		if (sapling[i]->getPos() == offScreenPos)
		{
			sapling[i]->setAttacked();
		}
	}
	if (!sapling[selectedSapling]->getAttack())
	{
		sapling[selectedSapling]->attack(*enemy[enemySelected]);
		myHud.getAction(selectedSapling, enemySelected, sapling[selectedSapling]->getDamgage());
	}
}
/// <summary>
/// creates warriors and rangers
/// </summary>
void Game::createRoots()
{
	for (int i = 0; i < currentSaplings; i++)
	{
		randomPos = rand() % 6;
		if (randomPos % 2 == 0)
		{
			while (myGrid[randomPos].checkOccupied())
			{
				randomPos = rand() % 6;
			}
			sapling[i] = new Base;
			sapling[i]->init();
			sapling[i]->setType(Type::ARCHER);
			sapling[i]->setPosition(sf::Vector2f(positions[randomPos].x + 100, positions[randomPos].y + 100));
			myGrid[randomPos].setOccupied();
			sapling[i]->setGridNumber(randomPos);
			myGrid[randomPos].setEnemyNumber(i);

		}
		else
		{

			while (myGrid[randomPos].checkOccupied())
			{
				randomPos = rand() % 6;
			}
			sapling[i] = new Base;
			sapling[i]->init();
			sapling[i]->setType(Type::FIGHTER);
			sapling[i]->setPosition(sf::Vector2f(positions[randomPos].x + 100, positions[randomPos].y + 100));
			myGrid[randomPos].setOccupied();
			sapling[i]->setGridNumber(randomPos);
			myGrid[randomPos].setEnemyNumber(i);

		}
	}

}
/// <summary>
/// ai for enemy decisions
/// </summary>
void Game::enemyMove()
{

	enemyMoveTimer++;
	if (enemyMoveTimer > 100)
	{
		randomEnemyNumber = 0;
		if (attackingEnemy < 0)
		{
			for (int i = 0; i < currentSaplings; i++)
			{
				sapling[i]->resetAttacks();
				myHud.startTurn();
				enemyMoveTimer = 0;
				randomEnemyNumber = 1;
			}
			m_gamestate = GameState::PLAYERTURN;
		}
		switch (randomEnemyNumber)
		{
		case 0:
			enemyStartLetter = true;
			enemyAttack();
			enemyMoveTimer = 0;
			break;
		case 1:
			//enemyHeal();
			break;
		case 2:
			//enemyHeal();
			break;
		default:
			break;
		}
	}
}
/// <summary>
/// enemy attacking function
/// </summary>
void Game::enemyAttack()
{
	int random = rand() % currentSaplings;
	
	if (!enemy[attackingEnemy]->checkDead())
	{
		while (sapling[random]->getAlive())
		{
			random = rand() % currentSaplings;
		}
		m_enemyText.setPosition(sapling[random]->getPos());
		sapling[random]->takeDamage(enemy[attackingEnemy]->getDamage());
		myHud.getEnemyAction(attackingEnemy, random, enemy[attackingEnemy]->getDamage());
		startLetter = true;
	}
	else
	{
		enemy[attackingEnemy]->setPosition(offScreenPos);
		numOfDeadEnemies++;
	}
	attackingEnemy--;
	
}
/// <summary>
/// enemy healing function
/// </summary>
void Game::enemyHeal()
{
	//int random = rand() % currentEnemies;
}
/// <summary>
/// displaces enemy at 0 hp
/// </summary>
void Game::killEnemy()
{
	for (int i = 0; i < currentEnemies; i++)
	{
		if (enemy[i]->getHealth() <= 0)
		{
			enemy[i]->kill();
		}
	}
}

void Game::killSaplings()
{
	for  (int i = 0; i <currentSaplings; i++)
	{
		if(sapling[i]->getHealth() <= 0)
		{
			sapling[i]->kill();
		}
	}
}

/// <summary>
/// hover over icons makes them fade, lets player see where they are
/// </summary>
void Game::mousePos()
{
	sf::Vector2i mousePs = sf::Mouse::getPosition(m_window);
	m_attackSprite.setColor(sf::Color(255, 255, 255, 255));
	m_turnOverSprite.setColor(sf::Color(255, 255, 255, 255));
	if (mousePs.x > m_attackSprite.getPosition().x && mousePs.x < m_attackSprite.getPosition().x + 80
		&& mousePs.y>m_attackSprite.getPosition().y && mousePs.y < m_attackSprite.getPosition().y + 80)
	{
		m_attackSprite.setColor(sf::Color(255, 255, 255, 132));
	}
	if (mousePs.x > m_turnOverSprite.getPosition().x && mousePs.x < m_turnOverSprite.getPosition().x + 80
		&& mousePs.y>m_turnOverSprite.getPosition().y && mousePs.y < m_turnOverSprite.getPosition().y + 80)
	{
		m_turnOverSprite.setColor(sf::Color(255, 255, 255, 132));
	}

	
}
/// <summary>
/// jumps damage text when dealing damage
/// </summary>
void Game::damageNumberAnimate()
{
	sf::Vector2f pos{ m_text.getPosition() };
	if (!hasSpawned)
	{
		textVelocity.y = -sqrtf(2.0f * 1.0f * 200);
		hasSpawned = true;
	}
	m_text.setString(std::to_string(sapling[selectedSapling]->getDamgage()));
	textVelocity.y+=2;

	pos += textVelocity;
	m_text.setPosition(pos);
	
	if (m_text.getPosition().y > 1080)
	{
		m_text.setPosition(offScreenPos);
		hasSpawned = false;
		startLetter = false;
	}
}
/// <summary>
/// animaating enemy damage numbers
/// </summary>
void Game::enemyNumbersAnimate()
{
	sf::Vector2f pos{ m_enemyText.getPosition() };
	if (!enemyLetterSpawned)
	{
		textVelocity.y = -sqrtf(2.0f * 1.0f * 200);
		enemyLetterSpawned = true;
	}
	m_enemyText.setString(std::to_string(enemy[attackingEnemy+1]->getDamage()));
	textVelocity.y += 2;

	pos += textVelocity;
	m_enemyText.setPosition(pos);

	if (m_enemyText.getPosition().y > 1080)
	{
		enemyLetterSpawned = false;
		enemyStartLetter = false;
	}
}

//checks game over very messy code but works
void Game::checkGameOver()
{
	switch (currentSaplings)
	{
	case 1:
		if (sapling[0]->getAlive())
		{
			m_gamestate = GameState::GAMEOVER;
		}
		break;
	case 2:
		if (sapling[0]->getAlive() && sapling[1]->getAlive())
		{
			m_gamestate = GameState::GAMEOVER;
		}
		break;
	case 3:
		if (sapling[0]->getAlive() && sapling[1]->getAlive() && sapling[2]->getAlive())
		{
			m_gamestate = GameState::GAMEOVER;
		}
		break;
	case 4:
		if (sapling[0]->getAlive() && sapling[1]->getAlive() && sapling[2]->getAlive() && sapling[3]->getAlive())
		{
			m_gamestate = GameState::GAMEOVER;
		}
		break;
	case 5:
		if (sapling[0]->getAlive() && sapling[1]->getAlive() && sapling[2]->getAlive() && sapling[3]->getAlive() && sapling[4]->getAlive())
		{
			m_gamestate = GameState::GAMEOVER;
		}
		break;
	case 6:
		if (sapling[0]->getAlive() && sapling[1]->getAlive() && sapling[2]->getAlive() && sapling[3]->getAlive() && sapling[4]->getAlive() && sapling[5]->getAlive())
		{
			m_gamestate = GameState::GAMEOVER;
		}
		break;
	}

}
void Game::checkGameWin()
{
	switch (currentEnemies)
	{
	case 1:
		if (enemy[0]->checkDead())
		{
			m_gamestate = GameState::TRANSITION;
		}
		break;
	case 2:
		if (enemy[0]->checkDead() && enemy[1]->checkDead())
		{
			m_gamestate = GameState::TRANSITION;
		}
		break;
	case 3:
		if (enemy[0]->checkDead() && enemy[1]->checkDead() && enemy[2]->checkDead())
		{
			m_gamestate = GameState::TRANSITION;
		}
		break;
	case 4:
		if (enemy[0]->checkDead()&& enemy[1]->checkDead() && enemy[2]->checkDead() && enemy[3]->checkDead())
		{
			m_gamestate = GameState::TRANSITION;
		}
		break;
	case 5:
		if (enemy[0]->checkDead() && enemy[1]->checkDead() && enemy[2]->checkDead() && enemy[3]->checkDead() && enemy[4]->checkDead())
		{
			m_gamestate = GameState::TRANSITION;
		}
		break;
	case 6:
		if (enemy[0]->checkDead() && enemy[1]->checkDead() && enemy[2]->checkDead() && enemy[3]->checkDead() && enemy[4]->checkDead() && enemy[5]->checkDead())
		{
			m_gamestate = GameState::TRANSITION;
		}
		break;
	}
}
/// <summary>
/// deletes enemies and sprouts
/// </summary>
void Game::deleteEntites()
{
	for (int i = 0; i < currentEnemies; i++)
	{
		delete enemy[i];
	}
	for (int i = 0; i < currentSaplings; i++)
	{
		delete sapling[i];
	}
}
/// <summary>
/// resets necessary variables for a new game
/// </summary>
void Game::resetVars()
{
	m_text.setPosition(offScreenPos);
	m_enemyText.setPosition(offScreenPos);

	attackingEnemy = currentEnemies;
	enemyMoveTimer = 0;
	randomEnemyNumber = 0;
	numOfDeadEnemies = 0;

	selectedSapling = 0;
	enemySelected = 0;
	healSelection = 0;

	hasMoved = false;
	heldMouse = false;

	for (int i = 0; i < 6; i++)
	{
		myGrid[i].reset();
		enemyGrid[i].reset();
	}
}
/// <summary>
/// checks grids when moving around player sprites
/// </summary>
void Game::checkGrids()
{
	for (int i = 0; i < 6; i++)
	{
		if (sapling[selectedSapling]->getPos().x > positions[i].x && sapling[selectedSapling]->getPos().x < positions[i].x + 200 &&
			sapling[selectedSapling]->getPos().y > positions[i].y && sapling[selectedSapling]->getPos().y < positions[i].y + 200)
		{
			if (!myGrid[i].checkOccupied())
			{
				myGrid[sapling[selectedSapling]->checkGridNumber()].setUnOccupied();
				myGrid[i].setOccupied();
				myGrid[i].setEnemyNumber(selectedSapling);
				sapling[selectedSapling]->setPosition(sf::Vector2f(positions[i].x + 100, positions[i].y + 100));
				sapling[selectedSapling]->setGridNumber(i);
				myHud.moveAction(selectedSapling, i);
				m_selectionSapling.setPosition(positions[i]);
			}
			else
			{
				sapling[selectedSapling]->setPosition(sf::Vector2f(positions[sapling[selectedSapling]->checkGridNumber()].x + 100, positions[sapling[selectedSapling]->checkGridNumber()].y + 100));
			}
		}
	}
}
/// <summary>
/// creates enemies
/// </summary>
void Game::createEnemies()
{
	for (int i = 0; i < currentEnemies; i++)
	{
		randomPos = rand() % 6;
		if (randomPos % 2 == 0)
		{
			while (enemyGrid[randomPos].checkOccupied())
			{
				randomPos = rand() % 6;
			}
				enemy[i] = new MeleeEnemy;
				enemy[i]->init();
				enemy[i]->setPosition(sf::Vector2f(ePositions[randomPos].x + 100, ePositions[randomPos].y + 100));
				enemyGrid[randomPos].setOccupied();
				enemyGrid[randomPos].setEnemyNumber(i);
			
		}
		else
		{

			while (enemyGrid[randomPos].checkOccupied())
			{
				randomPos = rand() % 6;
			}
				enemy[i] = new RangedEnemy;
				enemy[i]->init();
				enemy[i]->setPosition(sf::Vector2f(ePositions[randomPos].x + 100, ePositions[randomPos].y + 100));
				enemyGrid[randomPos].setOccupied();
				enemyGrid[randomPos].setEnemyNumber(i);
		
		}
	}
}




