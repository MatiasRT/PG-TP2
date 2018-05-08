#include "Bola.h"



Bola::Bola()
{
	ball.setSize(sf::Vector2f(5, 5));
	ball.setOrigin(ball.getSize().x / 2, ball.getPosition().y / 2);
	ball.setPosition(400, 300);
	ball.setFillColor(sf::Color(245, 147, 51));
}

Bola::~Bola()
{
}

void Bola::update(float _deltaTime, sf::RectangleShape player, int& _score)
{
	//// Movimiento ////
	ball.move(_deltaTime * velX, _deltaTime * velY);

	//// Restricciones ////
	// Derecha
	if (ball.getPosition().x > 800)
	{
		velX = -velX;
	}
	// Izquierda
	if (ball.getPosition().x < 0)
	{
		velX = -velX;
	}
	// Arriba
	if (ball.getPosition().y < 0)
	{
		velY = -velY;
	}
	// Abajo
	if (ball.getPosition().y > 600)
	{
		isOver = true;
		ball.setPosition(400, 300);
	}

	//// Colision ////
	if (((ball.getGlobalBounds().top + ball.getGlobalBounds().height) > player.getGlobalBounds().top)
		&& (ball.getGlobalBounds().left < (player.getGlobalBounds().left + player.getGlobalBounds().width))
		&& ((ball.getGlobalBounds().left + ball.getGlobalBounds().width) > player.getGlobalBounds().left)
		&& (ball.getGlobalBounds().top < (player.getGlobalBounds().top + player.getGlobalBounds().height)))
	{
		velY = -velY;
		_score += 1;
	}
	if (((ball.getGlobalBounds().left + ball.getGlobalBounds().width) > player.getGlobalBounds().left)
		&& ((ball.getGlobalBounds().top + ball.getGlobalBounds().height) > player.getGlobalBounds().top)
		&& (ball.getGlobalBounds().top < (player.getGlobalBounds().top + player.getGlobalBounds().height))
		&& (ball.getGlobalBounds().left < player.getGlobalBounds().left + 5))
	{
		velX = -velX;
	}
}

void Bola::draw(sf::RenderWindow & _window)
{
	_window.draw(ball);
}