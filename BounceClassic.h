#pragma once
#include "Ball.h"
#include "Tile.h"

class Game
{
public:
	Game();
	void Start();
	void Update();
	void Render();
	sf::RenderWindow window;
	sf::Event event;
private:
	sf::RectangleShape Box;
	Ball ball;
	int WIDTH;
	int HEIGHT;

	Tile test_tile;
};

Game::Game()
{
	WIDTH = 600;
	HEIGHT = 600;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "My Game!");
	window.setFramerateLimit(60);

}




void Game::Start() {
	Box.setSize(sf::Vector2f(20.0f, 20.0f));

	ball.setRadius(20);
	ball.setFillColor(sf::Color::Blue);

	

}



void Game::Update() {
	ball.Update();

	if (ball.getGlobalBounds().intersects(test_tile.getGlobalBounds()))
	{
		std::cout << "collision" << std::endl;
		ball.ballSpeed->x *= -1;
		ball.ballSpeed->y *= -1;
	}
}




void Game::Render() {
	window.draw(ball);
	window.draw(test_tile);
}