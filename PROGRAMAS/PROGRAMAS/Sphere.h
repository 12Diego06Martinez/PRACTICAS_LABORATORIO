#pragma once
#include "glut.h"
//Para  evitar  problemas  derivados  de  la  posible  redefinición  de  clases
#ifndef _ESFERA_H
#define _ESFERA_H 

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

#endif 
