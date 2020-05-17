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
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	int GetNumEsferas();
	bool GetImpacto() { return impacto; }
private:
	float x_eye;
	float y_eye;
	float z_eye;
	bool impacto;
	Bonus bonus;
	Caja caja;
	Humano humano;
	Pared plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;
};

