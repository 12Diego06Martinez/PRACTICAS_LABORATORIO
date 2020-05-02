#pragma once

#include "ListaEsferas.h"
#include "Interaction.h"

class InteraccionListas
{
public:
	InteraccionListas();
	~InteraccionListas();
	static void Rebote(ListaEsferas& s, Box b);
	static void Rebote(ListaEsferas& s, Wall w);
	static void Rebote(ListaEsferas& s);
	static Sphere* Colision(ListaEsferas& s, Human h);
};

