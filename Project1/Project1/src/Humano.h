#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Humano:public ObjetoMovil
{
public:
	Humano();
	virtual ~Humano();
	void Dibujar();
	void SetPos(float x, float y);
	void SetVelocidad(float x, float y);
	Vector2D GetPos();
	float GetAltura();
	friend class Interaccion;
private:
	float altura;
};

