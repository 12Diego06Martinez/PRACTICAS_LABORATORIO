#pragma once
#include "Shoot.h"
#include "Box.h"

#define MAX_SHOOT 10	

class ListaDisparos
{
public:
	ListaDisparos();
	~ListaDisparos();
	bool Add(Shoot* s);
	void Destroy();
	void Move(float t);
	void Collision(Wall w);
	void Collision(Box b);
private:
	Shoot* lista[MAX_SHOOT];
	int num;
};

