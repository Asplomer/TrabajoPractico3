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
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();

};

#endif // !MONEDA_H


