#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Humano.h"
#include "Disparo.h"
#include "Esfera.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"

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
	Humano humano;
	Pared plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;
};

