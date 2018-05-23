#include "Enemy.h"



Enemy::Enemy(float x, float y)
{
	sprite = al_load_bitmap("Asset/Goomba.png");
	positionX = x;
	positionY = y;
	spriteH = 64;
	spriteW = 64;
}


Enemy::~Enemy()
{
}

void Enemy::Movimiento()
{
}

void Enemy::Update()
{
	Movimiento();
}

ALLEGRO_BITMAP * Enemy::GetSprite()
{
	return sprite;
}

float Enemy::GetPosX()
{
	return 0.0f;
}

float Enemy::GetPosY()
{
	return 0.0f;
}

float Enemy::CollisionW()
{
	return 0.0f;
}

float Enemy::CollisionH()
{
	return 0.0f;
}
