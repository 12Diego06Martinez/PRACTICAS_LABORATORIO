#pragma once
#include "glut.h"

class Sphere
{
public:
	Sphere();
	~Sphere();
	void Draw();
	void Move();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetPos(float x, float y, float z);
	void SetRadius(float r);
private:
	float x;
	float y;
	float z;
	float radius;
	unsigned char red;
	unsigned char green;
	unsigned char blue;

};

Sphere::Sphere()
{
}

Sphere::~Sphere()
{
}
