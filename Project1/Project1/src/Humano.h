#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Humano:public ObjetoMovil
{
public:
	Humano();
	virtual ~Humano();
	void Dibujar();
	float GetAltura();
	friend class Interaccion;
private:
	float altura;
};

