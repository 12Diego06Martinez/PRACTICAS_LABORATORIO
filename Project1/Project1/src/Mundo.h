#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Humano.h"
#include "Disparo.h"
#include "Esfera.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "DisparoEspecial.h"

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
	int GetNumEsferas(){ return esferas.GetNum(); }
	bool GetImpacto() { return impacto; }
	bool CargarNivel();
private:
	float x_eye;
	float y_eye;
	float z_eye;
	bool impacto=false;
	int nivel=0;
	Bonus bonus;
	Caja caja;
	Humano humano;
	Pared plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;
	DisparoEspecial disparo_especial;
};

