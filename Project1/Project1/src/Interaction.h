#pragma once
/*Contiene las  posibles funciones que gestionarán las interacciones 
entre los distintos objetos de la escena. No tendrá en si entidad,
puesto que no  tendrá datos, sino que simplemente será responsable 
de agrupar todas estas funciones. */
#include "Human.h"
#include "Box.h"
#include "Sphere.h"

class Interaction {
public:
	Interaction();
	//virtual ~Interaction();
	static void Rebote(Human  &h, Box b);
	static bool Rebote(Sphere &s, Wall w);
	static bool Rebote(Sphere& s, Box b);
};