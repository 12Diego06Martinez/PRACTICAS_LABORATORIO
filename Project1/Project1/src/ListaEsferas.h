#pragma once
#include "Sphere.h"
#include "Interaction.h"

#define MAX_NUM 100

class ListaEsferas
{
public:
	ListaEsferas();
	virtual ~ListaEsferas();
	bool Add(Sphere* e);
	void Draw();
	void Move(float t);
	int GetNum() { return num; }
	void Destroy();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Sphere* esphere); //elimina la esfera apuntada por el puntero
	//Sphere* Colision(Human &h);
	Sphere* operator [](int pos);
private:
	Sphere* lista[MAX_NUM];
	int num;
};

