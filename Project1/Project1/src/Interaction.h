#pragma once
/*Contiene�las� posibles�funciones�que�gestionar�n�las�interacciones�
entre�los�distintos�objetos�de�la�escena.�No�tendr�en�si�entidad,
puesto�que�no� tendr�datos,�sino�que�simplemente�ser�responsable�
de�agrupar�todas�estas�funciones.�*/
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