#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

bool rect_overlaps(const float x1, const float y1, const float w1, const float h1, const float x2, const float y2, const float w2, const float h2) {

	return ((x1 < x2 + w2) && (x2 < x1 + w1) && (y1 < y2 + h2) && (y2 < y1 + h1));

}

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *mario = NULL;
	ALLEGRO_BITMAP *enemy = NULL;
	float positionX = 0;
	float positionY =0 ;
	float marioW = 64;
	float marioH = 64;
	float enemyPositionX = SCREEN_W - 128;
	float enemyPositionY = SCREEN_H - 128;
	float enemyW = 64;
	float enemyH = 64;
	int enemyDirX = -1;
	int enemyDirY = -1;
	bool redraw = true;
	bool gameOver = false;

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

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	mario = al_load_bitmap("Asset/Mario.png");
	if (!mario) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	enemy = al_load_bitmap("Asset/Goomba.png");
	if (!enemy) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(mario);
	al_set_target_bitmap(enemy);

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(mario);
		al_destroy_bitmap(enemy);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_flip_display();

	al_start_timer(timer);

	while (!gameOver)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
				positionY += 10;
			else if (ev.keyboard.keycode == ALLEGRO_KEY_UP)
				positionY -= 10;
			else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
				positionX -= 10;
			else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
				positionX += 10;
		}
		if (enemyPositionX <= 0 && enemyDirX != 1)
			enemyDirX = 1;
		else if (enemyPositionX >= SCREEN_W - enemyW && enemyDirX != -1)
			enemyDirX = -1;
		if (enemyPositionY <= 0 && enemyDirY != 1)
			enemyDirY = 1;
		else if (enemyPositionY >= SCREEN_H - enemyH && enemyDirY != -1)
			enemyDirY = -1;
		enemyPositionY += enemyDirY * 2;
		enemyPositionX += enemyDirX * 2;
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(mario, positionX, positionY, 0);
			al_draw_bitmap(enemy, enemyPositionX, enemyPositionY, 0);

			al_flip_display();
		}
		if (rect_overlaps(positionX,positionY,marioW,marioH,enemyPositionX,enemyPositionY,enemyW,enemyH))
		{
			gameOver = true;
		}
	}

	al_destroy_bitmap(mario);
	al_destroy_bitmap(enemy);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}