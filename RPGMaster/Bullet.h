#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Player.h"
	class Bullet
	{
	private:
		ALLEGRO_BITMAP * sprite = NULL;
		float positionX;
		float positionY;
		float spriteW;
		float spriteH;
		bool r;
		bool disp;
	public:
		Bullet(float posX, float posY, bool right);
		~Bullet();
		void Update(float x, float y);
		void Draw();
		ALLEGRO_BITMAP* GetSprite();
		float GetPosX();
		float GetPosY();
		float CollisionW();
		float CollisionH();
		float GetDisp();
		void Move(bool right);
		bool SetR(bool right);
	};

#endif