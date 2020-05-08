#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Humano.h"
#include "Disparo.h"
#include "Esfera.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"

class Mundo
{
public:
	Mundo();
	virtual ~Mundo();
	void Dibujar();
	void Mueve();
	void Inicializa();
	void SpecialKey(unsigned char key);
	void Key(unsigned char key);
private:
	float x_eye;
	float y_eye;
	float z_eye;
	Bonus bonus;
	Caja caja;
	Esfera esfera1;
	Esfera esfera2;
	Humano humano;
	Pared plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;
	EsferaPulsante esfera_pulsante;
};

