#pragma once
#include "Pared.h"

class Caja
{
public:
	Caja();
	virtual ~Caja();
	void Dibujar();
	friend class Interaccion;
private:
	Pared tejado;
	Pared suelo;
	Pared izquierda;
	Pared derecha;
};

