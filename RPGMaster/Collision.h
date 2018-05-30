#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Enemy.h"

class Collision
{
public:
	static bool AABB(const float x1, const float y1, const float w1, const float h1, const float x2, const float y2, const float w2, const float h2);
	static bool AABB(Player* p, Enemy* e);
};

#endif // !COLLISION_H



