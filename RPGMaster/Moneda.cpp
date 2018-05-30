#include "Moneda.h"



Moneda::Moneda(int posX, int posY)
{
	sprite = al_load_bitmap("Asset/Moneda.png");
	positionX = posX;
	positionY = posY;
	width = 16;
	height = 16;
}

Moneda::~Moneda()
{
	al_destroy_bitmap(sprite);
}

int Moneda::GetPosX()
{
	return positionX;
}

int Moneda::GetPosY()
{
	return positionY;
}

int Moneda::GetWidth()
{
	return width;
}

int Moneda::GetHeight()
{
	return height;
}

ALLEGRO_BITMAP * Moneda::GetSprite()
{
	return sprite;
}

void Moneda::Take()
{
	delete this;
}
