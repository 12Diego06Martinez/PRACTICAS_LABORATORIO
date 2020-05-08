#pragma once
#include "Esfera.h"

class EsferaPulsante: public Esfera
{
private:
	float pulso;//velocidad pulso de la esfera
	float radio_max;
	float radio_min;
public:
	//EsferaPulsante();
	EsferaPulsante(float p=0.5f, float r_max=2.0f, float r_min=0.5f, float x=0.0f, float y=5.0f, float vx=0.0f, float vy=0.0f);
	virtual ~EsferaPulsante();
	void Mueve(float t);
};

