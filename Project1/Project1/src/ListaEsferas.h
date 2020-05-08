#pragma once
#include "Esfera.h"
#include "Interaccion.h"

#define MAX_NUM 100

class ListaEsferas
{
public:
	ListaEsferas();
	virtual ~ListaEsferas();
	bool Agregar(Esfera* e);
	void Dibujar();
	void Mueve(float t);
	void Destruir();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Esfera* esfera); //elimina la esfera apuntada por el puntero
	int GetNum() { return num; }
	Esfera* operator [](int pos);
private:
	Esfera* lista[MAX_NUM];
	int num;
};

