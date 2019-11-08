#ifndef block_h
#define block_h

#include <SFML/Graphics.hpp>

using namespace sf;

class Block
{
private:
	Vector2f halfSize = Vector2f(10.0f, 10.0f);

	Vector2f position, speed;

	RectangleShape blockShape;

public:
	Block(Vector2f startCenter, sf::Color color);

	FloatRect getPosition();

	RectangleShape getShape();

	void update();
};

#endif /*block_h*/