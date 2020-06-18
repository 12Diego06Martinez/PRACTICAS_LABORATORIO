#pragma once

#include "Vector2D.h"

class ObjetoMovil
{
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	ObjetoMovil();
	virtual ~ObjetoMovil();
	virtual void Mueve(float t);
	void SetPos(float x, float y);
	void SetPos(Vector2D pos);
	void SetVel(float vx, float vy);
	Vector2D GetPos() { return posicion; }
	
};

