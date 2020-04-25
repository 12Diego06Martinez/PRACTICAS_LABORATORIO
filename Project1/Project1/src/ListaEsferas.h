#pragma once
#include "Sphere.h"

#define MAX_NUM 100

class ListaEsferas
{
public:
	ListaEsferas();
	bool Add(Sphere* e);
	void Draw();
	void Move(float t);
private:
	Sphere* lista[MAX_NUM];
	int num;
};

