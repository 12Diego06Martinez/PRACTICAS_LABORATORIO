#pragma once
#include "Vector2D.h"

class Pared
{
public:
	Pared();
	virtual ~Pared();
	void Dibujar();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetLimites(float x1, float y1, float x2, float y2);
	float Distancia(Vector2D point, Vector2D* direction = 0);
	friend class Interaccion;
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
};

