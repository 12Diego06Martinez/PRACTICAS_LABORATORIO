#pragma once
#include "Vector2D.h"

class Bonus{
public:
	Bonus();
	//virtual ~Bonus();
	void Draw();
	void Move(float t);
	void SetPos(float x, float y);
	void SetSide(float s);
private:
	float side;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

