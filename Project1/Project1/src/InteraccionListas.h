#pragma once

#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "Interaccion.h"

class InteraccionListas
{
public:
	InteraccionListas();
	~InteraccionListas();
	static void Rebote(ListaEsferas& e, Caja c);
	static void Rebote(ListaEsferas& e, Pared p);
	static void Rebote(ListaEsferas& e);
	static Esfera* Colision(ListaEsferas& e, Humano& h);
	static void Colision(ListaDisparos& e, Pared p);
	static void Colision(ListaDisparos& e, Caja c);
};

