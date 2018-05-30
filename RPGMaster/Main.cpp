#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
	
	int main(int argc, char **argv)
	{
		Game* game = new Game(640, 480, 30);
		while (!game->IsGameOver())
		{
			game->Update();
			game->Draw();
		}
		delete game;
		return 0;
	}