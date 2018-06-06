#include "Player.h"
#include "Bullet.h"

using namespace std;
Player::Player(float posX, float posY)
{
	sprite = al_load_bitmap("Asset/Mario.png");
	positionX = posX;
	positionY = posY;
	spriteH = 64;
	spriteW = 64;
	right = false;
	disparo = false;
}


Player::~Player()
{
}

void Player::Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
			positionY += 20;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP)
			positionY -= 20;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
			positionX -= 20;
			right = true;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
			positionX += 20;	//originalmente era 10 en todos
			right = false;
		}
		
		else if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
		{
			disparo = true;
			cout << "pew";
		}
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
float Player::GetRight() {
	return right;
}
void Player::Move(float x, float y)
{
	positionX += x;
	positionY += y;
}
bool Player::Pew() {
	return disparo;
}
