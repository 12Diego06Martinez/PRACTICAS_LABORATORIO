#pragma once

#ifndef _ESFERA_H
#define _ESFERA_H 
#include "glut.h"
//Para  evitar  problemas  derivados  de  la  posible  redefinición  de  clases


class Sphere
{
public:
	Sphere();
	//~Sphere()
	void Draw();
	void Move();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetPos(float xi, float yi, float zi);
	void SetRadius(float r);
	float GetRadius();
	void ChangePos(unsigned char key);

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

