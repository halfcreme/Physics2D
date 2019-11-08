#include "block.h"

Block::Block(Vector2f startCenter, sf::Color color)
{
	position = startCenter;
	blockShape.setPosition(position);
	blockShape.setSize(halfSize);
	blockShape.setOutlineThickness(1.0f);
	blockShape.setOutlineColor(sf::Color(130, 130, 130)); // light grey outline
	blockShape.setFillColor(color);
}

FloatRect Block::getPosition()
{
	return blockShape.getGlobalBounds();
}

RectangleShape Block::getShape()
{
	return blockShape;
}

void Block::update()
{
	position += speed;
	blockShape.setPosition(position);
}