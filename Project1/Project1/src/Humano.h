#pragma once
#include "ObjetoMovil.h"

class Humano:public ObjetoMovil
{
public:
	Humano();
	virtual ~Humano();
	void Dibujar();
	float GetAltura() { return altura; }
	friend class Interaccion;
private:
	float altura;
};

