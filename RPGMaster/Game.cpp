#include "Game.h"



Game::Game()
{

}


Game::~Game()
{
}

int Game::Initialize()
{
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize the Keyboard!\n");
		return -1;
	}
}
