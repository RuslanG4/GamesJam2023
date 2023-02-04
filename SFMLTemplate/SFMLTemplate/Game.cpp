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
	sapling = new Base;
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
}

void Game::processMouseRelease(sf::Event t_event)
{
	const int F_COL_1_LEFT = 200;
	const int F_COL_1_RIGHT = 400;
	const int F_ROW_1_TOP = 100;
	const int F_ROW_1_BOTTOM = 300;

	//Friendly archers Coloum 1 & process rows 
	if (t_event.mouseButton.x > F_COL_1_LEFT && t_event.mouseButton.x < F_COL_1_RIGHT)
	{
		if (t_event.mouseButton.y > F_ROW_1_TOP && t_event.mouseButton.y < F_ROW_1_BOTTOM)
		{
			std::cout << "Pressed friendly archer 1 box" << std::endl;
			fBox1 = true;
		}
		if (t_event.mouseButton.y > F_ROW_1_TOP + 200 && t_event.mouseButton.y < F_ROW_1_BOTTOM + 200)
		{
			std::cout << "Pressed friendly archer 2 box" << std::endl;
			fBox1 = true;
		}
		if (t_event.mouseButton.y > F_ROW_1_TOP + 400 && t_event.mouseButton.y < F_ROW_1_BOTTOM + 400)
		{
			std::cout << "Pressed friendly archer 3 box" << std::endl;
			fBox1 = true;
		}
	}
	//Friendly Fighters Coloum 2 & process rows
	if (t_event.mouseButton.x > F_COL_1_LEFT + 200 && t_event.mouseButton.x < F_COL_1_RIGHT + 200)
	{
		if (t_event.mouseButton.y > F_ROW_1_TOP && t_event.mouseButton.y < F_ROW_1_BOTTOM)
		{
			std::cout << "Pressed friendly fighters 1 box" << std::endl;
			fBox1 = true;
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

}
/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Green);

	for (int i = 0; i < 6; i++)
	{
		m_window.draw(m_grid[i]);
		m_window.draw(m_eGrid[i]);
	}
	sapling->render(m_window);
	m_window.display();
}

void Game::setupFontAndText()
{
	for (int i = 0; i < 6 ; i++)
	{
		m_grid[i].setSize(sf::Vector2f(200, 200));
		m_grid[i].setFillColor(sf::Color::Transparent);
		m_grid[i].setPosition(positions[i]);
		m_grid[i].setOutlineColor(sf::Color::Black);
		m_grid[i].setOutlineThickness(3);

		m_eGrid[i].setSize(sf::Vector2f(200, 200));
		m_eGrid[i].setFillColor(sf::Color::Transparent);
		m_eGrid[i].setPosition(ePositions[i]);
		m_eGrid[i].setOutlineColor(sf::Color::Black);
		m_eGrid[i].setOutlineThickness(3);
	}

	sapling->init();
	sapling->setPosition(sf::Vector2f(positions[0].x + 100, positions[0].y + 100));

}




