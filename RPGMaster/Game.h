#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Moneda.h"

class Game
{
private:
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	bool redraw = true;
	bool gameOver = false;
	int SCREEN_W;
	int SCREEN_H;
	int FPS;
	Player* mario;
	Enemy* goomba;
	Moneda* monedas = new Moneda[10];
public:
	Game(int SCREEN_W, int SCREEN_H, int FPS);
	~Game();
	int Initialize();
	void Draw();
	void Update();
	int EventInit();
	int CreateWindow();
	int CreateTimer();
	bool IsGameOver();
};

#endif // !GAME_H



