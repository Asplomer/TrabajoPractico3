#include "Player.h"

Player::Player(float posX, float posY)
{
	sprite = al_load_bitmap("Asset/Mario.png");
	positionX = posX;
	positionY = posY;
	spriteH = 64;
	spriteW = 64;
}


Player::~Player()
{
}

void Player::Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
			positionY += 10;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP)
			positionY -= 10;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
			positionX -= 10;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			positionX += 10;
	}
	if (positionX < 0)
		positionX = 0;
	else if (positionX > SCREEN_W - spriteW)
		positionX = SCREEN_W - spriteW;
	if (positionY < 0)
		positionY = 0;
	else if (positionY > SCREEN_H - spriteH)
		positionY = SCREEN_H - spriteH;
}

void Player::Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H) {
	Movimiento(ev, SCREEN_W, SCREEN_H);
}

void Player::Draw()
{
	al_draw_bitmap(sprite, positionX, positionY, 0);
}

ALLEGRO_BITMAP* Player::GetSprite()
{
	return sprite;
}

float Player::GetPosX() {
	return positionX;
}

float Player::GetPosY() {
	return positionY;
}

float Player::CollisionW()
{
	return spriteW;
}

float Player::CollisionH()
{
	return spriteH;
}

void Player::Move(float x, float y)
{
	positionX += x;
	positionY += y;
}
