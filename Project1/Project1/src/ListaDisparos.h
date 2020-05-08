#pragma once
#include "Disparo.h"
#include "Caja.h"
#include "Interaccion.h"

#define MAX_Disparo 10	

class ListaDisparos
{
public:
	ListaDisparos();
	~ListaDisparos();
	bool Agregar(Disparo* d);
	void Dibujar();
	void Destruir();
	void Mueve(float t);
	int GetNum() { return num; }
	Disparo* operator [](int pos);
private:
	Disparo* lista[MAX_Disparo];
	int num;
};

