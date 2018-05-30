#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Enemy.h"
#include "Moneda.h"

class Collision
{
public:
	static bool AABB(const float x1, const float y1, const float w1, const float h1, const float x2, const float y2, const float w2, const float h2);
	static bool AABB(Player* p, Enemy* e);
	static bool AABB(Player* p, Moneda* m);
};

#endif // !COLLISION_H



