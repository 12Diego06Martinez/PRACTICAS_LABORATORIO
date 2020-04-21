#pragma once
#include "Vector2D.h"

class Sphere
{
public:
	Sphere();
	//virtual ~Sphere();
	void Draw();
	void Move(float t);
	void SetPos(float x, float y);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetRadius(float rad);
	void SetSpeed(float x, float y);
	friend class Interaction;
private:
	float radius;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

