#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Bonus:public ObjetoMovil{
public:
	Bonus();
	virtual ~Bonus();
	void Dibujar();
	void Mueve(float t);
	void SetSide(float s);
	friend class Interaccion;
private:
	float lado;
};

