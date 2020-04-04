#pragma once
#include "Vector2D.h"

class Shoot
{
public:
	Shoot();
	//virtual ~Shoot();
	void Draw();
	void Move(float t);
	void SetRadius(float rad); //para el futuro
	void SetPos(float x, float y); //idem
private:
	float radius;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

