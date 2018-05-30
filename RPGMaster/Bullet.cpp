#include "Bullet.h"
#include "Player.h"


Bullet::Bullet(float posX, float posY, bool right)
{
	sprite = al_load_bitmap("Asset/Bullet.png");
	positionX = posX;
	positionY = posY;
	spriteH = 8;
	spriteW = 8;
	Draw();
	r = right;
	disp = false;
}


Bullet::~Bullet()
{
}



void Bullet::Update(float x, float y) {
	if (disp)
	{
		Move(r);
	}
	
}

void Bullet::Draw()
{
	al_draw_bitmap(sprite, positionX, positionY, 0);
}

ALLEGRO_BITMAP* Bullet::GetSprite()
{
	return sprite;
}

float Bullet::GetPosX() {
	return positionX;
}

float Bullet::GetPosY() {
	return positionY;
}

float Bullet::GetDisp() {
	return disp;
}

float Bullet::CollisionW()
{
	return spriteW;
}

float Bullet::CollisionH()
{
	return spriteH;
}

void Bullet::Move(bool right)
{
	if (right)
	{
		positionX += 2;
		//positionY += y;
	}
	else
	{

		positionX -= 2;
		//positionY -= y;
	}
}
