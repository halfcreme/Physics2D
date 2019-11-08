#ifndef game_h
#define game_h

#include "player.h"
#include "block.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	player_h::Player player;
	block_h::Block blockOne;
	block_h::Block blockTwo;

	bool mMoveLeft, mMoveRight, mJump, mPickup, mDrop;

	void processEvent();

	void update();

	void render();

	void handleInput(sf::Keyboard::Key key, bool isPressed);

public:
	Game();

	void run();
};

#endif /*game_h*/