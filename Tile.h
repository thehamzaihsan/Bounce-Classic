#pragma once

class Tile:public sf::RectangleShape
{
public:
	Tile();

private:

};

Tile::Tile()
{
	this->setPosition(sf::Vector2f(300, 550));
	this->setSize(sf::Vector2f(50, 50));
}

