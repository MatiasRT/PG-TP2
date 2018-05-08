#pragma once

#include <sfml/Graphics.hpp>
#include <sfml/Audio.hpp>
#include <iostream>
#include "Personaje.h"
#include "Bola.h"

class Juego
{
public:
	Juego();
	~Juego();

	sf::RenderWindow window;
	enum GameState { MENU, OPTIONS, GAME, OVER, END };
	GameState state;

	void runGame();

	// Menu State
	void menu();
	void play();
	void options();
	void over();

	sf::Font font1;
	sf::Font font;
	sf::Music music;

	int scoreOverall = 0;

	float deltaTime = 0.0f;
};