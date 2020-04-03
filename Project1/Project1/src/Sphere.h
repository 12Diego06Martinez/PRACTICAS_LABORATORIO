#pragma once
#include "Vector2D.h"

class Sphere
{
public:
	Sphere();
	//virtual ~Sphere();
	void Draw();
	void Move(float t);
private:
	float radius;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

