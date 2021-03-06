#include "Personaje.h"

Personaje::Personaje()
{
	player.setSize(sf::Vector2f(70, 10));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setFillColor(sf::Color(245, 147, 51));
	player.setPosition(650, 560);
}

Personaje::~Personaje()
{
}

void Personaje::update(float _deltaTime)
{
	//// Input del jugador ////
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerVelocity += _deltaTime * 3000.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerVelocity -= _deltaTime * 3000.0f;
	}

	//// Velocidad maxima del jugador ////
	if (playerVelocity > 500.0f)
	{
		playerVelocity = 500.0f;
	}
	if (playerVelocity < -500.0f)
	{
		playerVelocity = -500.0f;
	}

	//// Friccion del jugador ////
	if (playerVelocity > 0)
	{
		playerVelocity -= _deltaTime * 1000.0f;
	}
	if (playerVelocity < 0)
	{
		playerVelocity += _deltaTime * 1000.0f;
	}

	//// Limites del jugador ////
	if (player.getPosition().x > 800)
	{
		player.setPosition(800, player.getPosition().y);
		playerVelocity = 0;
	}
	if (player.getPosition().x < 0)
	{
		player.setPosition(0, player.getPosition().y);
		playerVelocity = 0;
	}

	playerVelocity = std::floor(playerVelocity * 10 + 0.5f) / 10;

	player.move(_deltaTime * playerVelocity, 0);
}

void Personaje::draw(sf::RenderWindow& _window)
{
	_window.draw(player);
}

sf::RectangleShape Personaje::getRect()
{
	return player;
}
