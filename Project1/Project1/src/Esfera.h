#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Esfera:public ObjetoMovil
{
public:
	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Esfera();
	void Dibujar();
	void SetPos(float x, float y);
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetRadio(float rad);
	void Setvelocidad(float x, float y);
	friend class Interaccion;
private:
	float radio;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};

