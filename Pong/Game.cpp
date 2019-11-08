#include "game.h"

Game::Game()
	: window(sf::VideoMode(800, 600), "Physics2D")
	, player(Vector2f(20, 580))
	, blockOne(Vector2f(100, 580), sf::Color::Cyan)
	, blockTwo(Vector2f(160, 580), sf::Color::Yellow)
	, mMoveLeft(false)
	, mMoveRight(false)
	, mJump(false)
	, mPickup(false)
	, mDrop(false)
{
	window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvent();
		update();
		render();
	}
}

void Game::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handleInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handleInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Game::update()
{
	player.update(mMoveLeft, mMoveRight, mJump, mPickup, mDrop);
	blockOne.update();
	blockTwo.update();
}

void Game::render()
{
	window.clear(sf::Color(140, 220, 250, 255)); // light blue screen
	
	// TODO: refactor for function to draw array of objects

	window.draw(player.getShape());
	window.draw(blockOne.getShape());
	window.draw(blockTwo.getShape());

	window.display();
}

void Game::handleInput(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::A:
		mMoveLeft = isPressed;
		break;
	case sf::Keyboard::D:
		mMoveRight = isPressed;
		break;
	case sf::Keyboard::W:
		mJump = isPressed;
		break;
	case sf::Keyboard::J:
		mPickup = isPressed;
		break;
	case sf::Keyboard::K:
		mDrop = isPressed;
		break;
	case sf::Keyboard::Escape:
		window.close();
		break;



	case sf::Keyboard::Space:
		sf::CircleShape shape(50.f);
		shape.setFillColor(sf::Color::Black);
		shape.setPosition(Vector2f(100, 100));
		window.draw(shape);
		break;
	}

}