#ifndef player_h
#define player_h

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	Vector2f halfSize = Vector2f(10.0f, 10.0f);

	float runSpeed = 10.0f, jumpSpeed = -10.0f;

	Vector2f position, speed;

	RectangleShape playerShape;

	// bool touchRight, touchLeft, touchBottom, touchTop;

	enum State
	{
		STATE_RUN,
		STATE_JUMP,
		STATE_PICKUP,
		STATE_DROP,
		STATE_STILL
	};

	State currentState = STATE_STILL;

public:
	Player(Vector2f start);

	FloatRect getPosition();

	RectangleShape getShape();
	
	void update(bool moveLeft, bool moveRight, bool jump, bool pickup, bool drop);
};

#endif /*player_h*/