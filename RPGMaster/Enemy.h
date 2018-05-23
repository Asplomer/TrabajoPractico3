#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Enemy
{
private:
	ALLEGRO_BITMAP * sprite = NULL;
	float positionX;
	float positionY;
	float spriteW;
	float spriteH;
	int directionX;
	int directionY;
public:
	Enemy(float x, float y);
	~Enemy();
	void Movimiento(const int SCREEN_W, const int SCREEN_H);
	void Update(const int SCREEN_W, const int SCREEN_H);
	ALLEGRO_BITMAP* GetSprite();
	float GetPosX();
	float GetPosY();
	float CollisionW();
	float CollisionH();
};

#endif