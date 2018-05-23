#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
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
	void Movimiento(ALLEGRO_EVENT ev);
	void Update(ALLEGRO_EVENT ev);
	ALLEGRO_BITMAP* GetSprite();
	float GetPosX();
	float GetPosY();
	float CollisionW();
	float CollisionH();
	void Move(float x, float y);
};

#endif // !PLAYER_H





