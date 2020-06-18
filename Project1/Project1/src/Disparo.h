#pragma once
#include "ObjetoMovil.h"

class Disparo: public ObjetoMovil
{
public:
	Disparo();
	Disparo(float radio, float x=0.0f, float y=0.0f, float vx=0.0f, float vy=0.0f);
	virtual ~Disparo();
	virtual void Dibujar();
	void SetRadio(float rad); //altura
	void SetPos(float x, float y);
	void SetPos(Vector2D pos);
	float GetRadio() { return radio; }
	void SetOrigen(Vector2D o);
	friend class Interaccion;
protected:
	float radio;
	Vector2D origen;
};

