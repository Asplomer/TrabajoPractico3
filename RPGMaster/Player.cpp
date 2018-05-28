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

void Player::Movimiento(ALLEGRO_EVENT ev)
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
}

void Player::Update(ALLEGRO_EVENT ev) {
	Movimiento(ev);
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
