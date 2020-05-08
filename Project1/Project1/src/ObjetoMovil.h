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
	void Mueve(float t);
};

