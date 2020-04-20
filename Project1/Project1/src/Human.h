#pragma once
#include "Vector2D.h"

class Human
{
public:
	Human();
	//virtual ~Human();
	void Draw();
	void Move(float t);
	void SetPos(float x, float y);
	void SetSpeed(float x, float y);
private:
	float height;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

