#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Disparo: public ObjetoMovil
{
public:
	Disparo();
	Disparo(float radio, float x=0.0f, float y=0.0f, float vx=0.0f, float vy=0.0f);
	virtual ~Disparo();
	void Dibujar();
	void SetRadio(float rad); //altura
	void SetPos(float x, float y);
	void Setvelocidad(float vx, float vy);
	void SetAcel(float ax, float ay);
	float GetRadio() { return radio; }
	Vector2D GetPos() { return posicion; }
private:
	float radio;
	Vector2D origen;
};

