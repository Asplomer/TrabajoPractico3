#include "Enemy.h"



Enemy::Enemy(float x, float y)
{
	sprite = al_load_bitmap("Asset/Goomba.png");
	positionX = x;
	positionY = y;
	spriteH = 64;
	spriteW = 64;
	directionX = -1;
	directionY = -1;
}


Enemy::~Enemy()
{
}

void Enemy::Movimiento(const int SCREEN_W, const int SCREEN_H)
{
	if (positionX <= 0 && directionX != 1)
		directionX = 1;
	else if (positionX >= SCREEN_W - spriteW && directionX != -1)
		directionX = -1;
	if (positionY <= 0 && directionY != 1)
		directionY = 1;
	else if (positionY >= SCREEN_H - spriteH && directionY != -1)
		directionY = -1;
	positionY += directionY * 2;
	positionX += directionX * 2;
}

void Enemy::Update(const int SCREEN_W, const int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Enemy::Draw()
{
	al_draw_bitmap(sprite, positionX, positionY, 0);
}

ALLEGRO_BITMAP * Enemy::GetSprite()
{
	return sprite;
}

float Enemy::GetPosX()
{
	return positionX;
}

float Enemy::GetPosY()
{
	return positionY;
}

float Enemy::CollisionW()
{
	return spriteW;
}

float Enemy::CollisionH()
{
	return spriteH;
}
