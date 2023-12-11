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



void Game::Update() 
{
	ball.Update();
	
	if (ball.getGlobalBounds().intersects(test_tile.getGlobalBounds()))
	{
		if (ball.i - ball.v > 5) 
		{
			std::cout << "collision" << std::endl;
			
			if (ball.getPosition().y <= test_tile.getPosition().y || ball.getPosition().y >= test_tile.getPosition().y + 100)
			{
				if (ball.ballSpeed->y > 0)
					ball.setPosition(ball.getPosition().x, test_tile.getPosition().y - ball.getRadius() * 2);
				if (ball.ballSpeed->y < 0)
					ball.setPosition(ball.getPosition().x, test_tile.getPosition().y + 100 + ball.getRadius() * 2);
				ball.ballSpeed->y *= -1;
				
			}
			else if (ball.getPosition().y > test_tile.getPosition().y || ball.getPosition().y < test_tile.getPosition().y + 100)
				ball.ballSpeed->x *= -1;
			ball.v = ball.i;
		}
	}
}




void Game::Render() {
	window.draw(ball);
	window.draw(test_tile);
}