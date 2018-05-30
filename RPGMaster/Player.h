#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Player
{
private:
	ALLEGRO_BITMAP *sprite = NULL;
	float positionX;
	float positionY;
	float spriteW;
	float spriteH;
public:
	Player(float posX, float posY);
	~Player();
	void Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H);
	void Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H);
	void Draw();
	ALLEGRO_BITMAP* GetSprite();
	float GetPosX();
	float GetPosY();
	float CollisionW();
	float CollisionH();
	void Move(float x, float y);
};

#endif // !PLAYER_H





