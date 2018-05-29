#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

int main(int argc, char **argv)
{
	Game* game = new Game(640, 480, 60);



	while (!game->IsGameOver())
	{

		mario->Update(ev);
		goomba->Update(SCREEN_W, SCREEN_H);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			mario->Draw();
			goomba->Draw();

			al_flip_display();
		}

		if (Collision::AABB(mario->GetPosX(), mario->GetPosY(), mario->CollisionW(), mario->CollisionH(), goomba->GetPosX(), goomba->GetPosY(), goomba->CollisionW(), goomba->CollisionH()))
		{
			gameOver = true;
		}
	}

	al_destroy_bitmap(mario->GetSprite());
	al_destroy_bitmap(goomba->GetSprite());
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	delete mario;
	delete goomba;

	return 0;
}