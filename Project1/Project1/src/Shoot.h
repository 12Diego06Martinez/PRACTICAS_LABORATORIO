#pragma once
#include "Vector2D.h"

class Shoot
{
public:
	Shoot();
	//virtual ~Shoot();
	void Draw();
	void Move(float t);
private:
	float radius;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

