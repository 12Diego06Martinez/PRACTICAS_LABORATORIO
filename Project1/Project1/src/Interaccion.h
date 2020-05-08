#pragma once
/*Contiene las  posibles funciones que gestionarán las interacciones 
entre los distintos objetos de la escena. No tendrá en si entidad,
puesto que no  tendrá datos, sino que simplemente será responsable 
de agrupar todas estas funcionee. */
#include "Humano.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"

class Interaccion {
public:
	Interaccion();
	//virtual ~Interaccion();
	static void Rebote(Humano  &h, Caja c);
	static bool Rebote(Esfera &e, Pared p);
	static void Rebote(Esfera& e, Caja c);
	static bool Rebote(Esfera& esfera1, Esfera& esfera2);
	static bool Colision(Esfera e, Humano h);
	static bool Colision(Disparo d, Pared p);
	static bool Colision(Disparo d, Caja c);
};