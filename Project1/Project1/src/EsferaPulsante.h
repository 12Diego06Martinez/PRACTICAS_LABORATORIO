#pragma once
#include "Esfera.h"

class EsferaPulsante: public Esfera
{
public:
	EsferaPulsante();
	virtual ~EsferaPulsante();
	void Mueve(float t);
	Esfera* Dividir();
	void SetPulso(float p) { pulso = p; }
private:
	float pulso;//velocidad pulso de la esfera
	float radio_max;
	float radio_min;
};

