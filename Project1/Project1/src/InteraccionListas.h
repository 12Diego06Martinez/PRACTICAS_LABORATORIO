#pragma once

#include "ListaEsferas.h"
#include "Interaction.h"

class InteraccionListas
{
public:
	InteraccionListas();
	~InteraccionListas();
	static void Rebote(ListaEsferas& s, Box b);
};

