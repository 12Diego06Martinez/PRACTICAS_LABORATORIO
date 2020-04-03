#pragma once
#include "Vector2D.h"


class Human
{
public:
	Human();
	virtual ~Human();
	void Draw();
	void Move(float t);
private:
	float height;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

