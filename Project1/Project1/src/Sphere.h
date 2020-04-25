#pragma once
#include "Vector2D.h"

class Sphere
{
public:
	Sphere();
	Sphere(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Sphere();
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

