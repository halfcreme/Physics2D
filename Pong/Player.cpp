#include "player.h"
#include "block.h"

Player::Player(Vector2f startCenter)
{
	position = startCenter;
	playerShape.setPosition(position);
	playerShape.setSize(halfSize);
	playerShape.setOutlineThickness(1.0f);
	playerShape.setOutlineColor(sf::Color(130, 130, 130)); // light grey outline
	playerShape.setFillColor(sf::Color::White);
}

FloatRect Player::getPosition()
{
	return playerShape.getGlobalBounds();
}

RectangleShape Player::getShape()
{
	return playerShape;
}

void Player::update(bool moveLeft, bool moveRight, bool jump, bool pickup, bool drop)
{
	switch (currentState)
	{
	case STATE_STILL:
		speed.x = 0.0f;
		speed.y = 0.0f;

		/*if (!touchBottom) // fall if not on object
		{
			speed.y = jumpSpeed;
			currentState = STATE_JUMP;
			break;
		}*/

		if (moveLeft != moveRight) // if either left or right are pressed, run
		{
			currentState = STATE_RUN;
			break;
		}
		else if (jump)
		{
			speed.y = jumpSpeed;
			currentState = STATE_JUMP;
			break;
		}

		break;

	case STATE_RUN:
		/*if (!touchBottom) // fall if not on object
		{
			speed.y = jumpSpeed;
			currentState = STATE_JUMP;
			break;
		}*/

		if (moveLeft == moveRight) // if left and right are not/both pressed, be still
		{
			speed.x = 0.0f;
			speed.y = 0.0f;
			currentState = STATE_STILL;
			break;
		}

		else if (moveLeft)
		{
			/*if (touchLeft)
				speed.x = 0.0f;
			else*/
				speed.x = -runSpeed;
		}
		else if (moveRight)
		{
			/*if (touchRight)
				speed.x = 0.0f;
			else*/
				speed.x = runSpeed;
		}
		break;

	case STATE_JUMP:
		break;

	case STATE_PICKUP:

		break;

	case STATE_DROP:
		break;
	}


	/*position += speed;
	playerShape.setPosition(position);*/
}