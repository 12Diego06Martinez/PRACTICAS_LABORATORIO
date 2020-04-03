#pragma once

#ifndef _ESFERA_H
#define _ESFERA_H 
#include "Vector2D.h"
//Para  evitar  problemas  derivados  de  la  posible  redefinición  de  clases


class Sphere
{
public:
	Sphere();
	virtual ~Sphere();
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

#endif 

