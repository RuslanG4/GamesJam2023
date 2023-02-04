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

			if (!myGrid[0].checkOccupied())
			{
				selectedSapling = myGrid[0].enemyNumberCheck();
				myGrid[0].setEnemyNumber(selectedSapling);
			}
			else
			{
				selectedSapling = myGrid[0].enemyNumberCheck();
			}

			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed friendly archer 2 box" << std::endl;

			selectedSapling = myGrid[2].enemyNumberCheck();
			myGrid[0].setEnemyNumber(selectedSapling);
			
			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed friendly archer 3 box" << std::endl;

			selectedSapling = myGrid[4].enemyNumberCheck();
			myGrid[0].setEnemyNumber(selectedSapling);
		
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

			selectedSapling = myGrid[1].enemyNumberCheck();
			myGrid[0].setEnemyNumber(selectedSapling);
		

			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed friendly fighters 2 box" << std::endl;

			selectedSapling = myGrid[3].enemyNumberCheck();
			myGrid[0].setEnemyNumber(selectedSapling);
		

			pressedBox = true;
			heldMouse = true;

		}
		if (t_event.mouseButton.y > F_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed friendly fighters 3 box" << std::endl;

			selectedSapling = myGrid[5].enemyNumberCheck();
			myGrid[0].setEnemyNumber(selectedSapling);
		

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
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed Enemy fighter 2 box" << std::endl;
			enemySelected = enemyGrid[2].enemyNumberCheck();
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed Enemy fighter 3 box" << std::endl;
			enemySelected = enemyGrid[4].enemyNumberCheck();
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
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 200 && t_event.mouseButton.y < F_ROW_BOTTOM + 200)
		{
			std::cout << "Pressed Enemy archer 2 box" << std::endl;
			enemySelected = enemyGrid[3].enemyNumberCheck();
			pressedBox = true;
		}
		if (t_event.mouseButton.y > E_ROW_TOP + 400 && t_event.mouseButton.y < F_ROW_BOTTOM + 400)
		{
			std::cout << "Pressed Enemy archer 3 box" << std::endl;
			enemySelected = enemyGrid[5].enemyNumberCheck();
			pressedBox = true;
		}

	}
	

}

void Game::processMouseRelease(sf::Event t_event)
{
	heldMouse = false;
	std::cout << "enemy selected : " + std::to_string(enemySelected);
	std::cout << "player selected : " + std::to_string(selectedSapling);
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

	attack();
	checkGrids();


	if (heldMouse)
	{
		movingSprite();
	}

}
/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Green);

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
	m_window.draw(attackButton);
	m_window.display();
}

void Game::setupFontAndText()
{
	for (int i = 0; i < 6 ; i++)
	{
		myGrid[i].setPosition(positions[i]);

		enemyGrid[i].setPosition(ePositions[i]);
	}

	attackButton.setSize(sf::Vector2f(200, 50));
	attackButton.setPosition(820, 330);

}

void Game::movingSprite()
{
	sapling[selectedSapling]->setPosition(sf::Vector2f(sf::Mouse::getPosition(m_window)));
}

void Game::attack()
{
	pressedAttack = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		pressedAttack = true;
	}

	if (pressedAttack)
	{
		if (!sapling[selectedSapling]->getAttack())
		{
			sapling[selectedSapling]->attack(*enemy[enemySelected]);
			pressedAttack = false;
		}
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
			sapling[i]->setType(Type::ARCHER);
			sapling[i]->init();
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
			sapling[i]->setType(Type::ARCHER);
			sapling[i]->init();
			sapling[i]->setPosition(sf::Vector2f(positions[randomPos].x + 100, positions[randomPos].y + 100));
			myGrid[randomPos].setOccupied();
			sapling[i]->setGridNumber(randomPos);
			myGrid[randomPos].setEnemyNumber(i);

		}
	}
}

void Game::checkGrids()
{
	//for (int i = 0; i < 6; i++)
	//{
	//	if (sapling[selectedSapling]->getPos().x > positions[i].x && sapling[selectedSapling]->getPos().x < positions[i].x + 200 &&
	//		sapling[selectedSapling]->getPos().y > positions[i].y && sapling[selectedSapling]->getPos().y < positions[i].y + 200 &&
	//		!myGrid[i].checkOccupied())
	//	{
	//		//myGrid[i].setEnemyNumber(selectedSapling);
	//		myGrid[i].setOccupied();
	//	}
	//}
	
}

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
				enemy[i]->setType(Type::FIGHTER);
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
				enemy[i]->setType(Type::ARCHER);
				enemy[i]->setPosition(sf::Vector2f(ePositions[randomPos].x + 100, ePositions[randomPos].y + 100));
				enemyGrid[randomPos].setOccupied();
				enemyGrid[randomPos].setEnemyNumber(i);
		
		}
	}
}




