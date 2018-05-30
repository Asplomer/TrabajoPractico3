#include "Moneda.h"



Moneda::Moneda(int posX, int posY)
{
	positionX = posX;
	positionY = posY;
}

Moneda::~Moneda()
{
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
