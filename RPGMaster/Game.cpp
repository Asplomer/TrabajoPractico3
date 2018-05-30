#include "Game.h"

Game::Game(int _SCREEN_W, int _SCREEN_H, int _FPS)
{
	SCREEN_W = _SCREEN_W;
	SCREEN_H = _SCREEN_H;
	FPS = _FPS;
	Initialize();
}

Game::~Game()
{
	// SE DESTRUYEN LOS OBJETOS
	al_destroy_bitmap(mario->GetSprite());
	al_destroy_bitmap(goomba->GetSprite());
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	delete mario;
	delete goomba;
}

int Game::Initialize()
{
	// SE INICIALIZA LA LIBRERIA ALLEGRO
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	// SE INICIALIZA SOPORTE IMAGENES
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	// SE INICIALIZA EL TECLADO
	if (!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize the Keyboard!\n");
		return -1;
	}
	// SE CREA DELTA TIME COMO TIMER
	CreateTimer();
	// SE CREA LA VENTANA
	CreateWindow();
	// SE CREAN PERSONAJES
	mario = new Player(0, 0);
	goomba = new Enemy(SCREEN_W - 128, SCREEN_H - 128);
	// SE CREA INPUT
	EventInit();
	// SE REGISTRAN IMAGENES Y EVENTOS
	al_set_target_bitmap(mario->GetSprite());
	al_set_target_bitmap(goomba->GetSprite());
	al_set_target_bitmap(al_get_backbuffer(display));

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	al_start_timer(timer);
}

void Game::Draw()
{
	if (redraw && al_is_event_queue_empty(event_queue)) {
		redraw = false;
		al_clear_to_color(al_map_rgb(0, 0, 0));
		mario->Draw();
		goomba->Draw();
		al_flip_display();
	}
}

void Game::Update()
{
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		redraw = true;
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		gameOver = true;
	}
	// UPDATE DE LOS PERSONAJES
	mario->Update(ev);
	goomba->Update(SCREEN_W, SCREEN_H);
	// COLLISION PERSONAJES
	if (Collision::AABB(mario,goomba))
		gameOver = true;
}

int Game::EventInit()
{
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(mario->GetSprite());
		al_destroy_bitmap(goomba->GetSprite());
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
}

int Game::CreateWindow()
{
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
}

int Game::CreateTimer()
{
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
}

bool Game::IsGameOver()
{
	return gameOver;
}
