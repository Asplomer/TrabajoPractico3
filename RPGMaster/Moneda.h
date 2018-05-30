#ifndef MONEDA_H
#define MONEDA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Moneda
{
private:
	ALLEGRO_BITMAP * sprite = NULL;
	int positionX;
	int positionY;
	int width;
	int height;
public:
	Moneda(int posX, int posY);
	~Moneda();
	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();
	ALLEGRO_BITMAP* GetSprite();
	void Take();
};

#endif // !MONEDA_H


