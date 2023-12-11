#pragma once

class Tile:public sf::RectangleShape
{
public:
	Tile();

private:

};

Tile::Tile()
{
	this->setPosition(sf::Vector2f(300, 300));
	this->setSize(sf::Vector2f(100, 100));
}

