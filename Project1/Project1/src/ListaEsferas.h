#pragma once
#include "Sphere.h"
#include "Interaction.h"

#define MAX_NUM 100

class ListaEsferas
{
public:
	ListaEsferas();
	bool Add(Sphere* e);
	void Draw();
	void Move(float t);
	void Rebote(Box box);
private:
	Sphere* lista[MAX_NUM];
	int num;
};

