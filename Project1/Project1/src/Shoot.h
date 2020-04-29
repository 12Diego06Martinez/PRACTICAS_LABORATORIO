#pragma once
#include "Vector2D.h"

class Shoot
{
public:
	Shoot();
	Shoot(float radius, float x=0.0f, float y=0.0f, float vx=0.0f, float vy=0.0f);
	virtual ~Shoot();
	void Draw();
	void Move(float t);
	void SetRadius(float rad); //altura
	void SetPos(float x, float y);
	void SetSpeed(float vx, float vy);
	void SetAcel(float ax, float ay);
	float GetRadius() { return radius; }
	Vector2D GetPos() { return position; }
private:
	float radius;
	Vector2D origin;
	Vector2D position;
	Vector2D speed;
	Vector2D aceleration;
};

