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

int Moneda::getPosX()
{
	return positionX;
}

int Moneda::getPosY()
{
	return positionY;
}

int Moneda::getWidth()
{
	return width;
}

int Moneda::getHeight()
{
	return height;
}

void Moneda::Take()
{
	delete this;
}
