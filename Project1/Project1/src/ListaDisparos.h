#pragma once
#include "Shoot.h"
#include "Box.h"
#include "Interaction.h"

#define MAX_SHOOT 10	

class ListaDisparos
{
public:
	ListaDisparos();
	~ListaDisparos();
	bool Add(Shoot* s);
	void Destroy();
	void Move(float t);
	void Colision(Wall w);
	void Colision(Box b);
private:
	Shoot* lista[MAX_SHOOT];
	int num;
};

