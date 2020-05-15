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
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetRadio(float rad);
	virtual Esfera* Dividir();
	friend class Interaccion;
protected:
	float radio;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};

