#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Game
{
public:
	Game();
	~Game();
	int Initialize();
};

#endif // !GAME_H



