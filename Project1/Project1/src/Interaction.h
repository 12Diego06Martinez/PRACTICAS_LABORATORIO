#pragma once
/*Contiene�las� posibles�funciones�que�gestionar�n�las�interacciones�
entre�los�distintos�objetos�de�la�escena.�No�tendr�en�si�entidad,
puesto�que�no� tendr�datos,�sino�que�simplemente�ser�responsable�
de�agrupar�todas�estas�funciones.�*/
#include "Human.h"
#include "Box.h"
#include "Sphere.h"
#include "Shoot.h"

class Interaction {
public:
	Interaction();
	//virtual ~Interaction();
	static void Rebote(Human  &h, Box b);
	static bool Rebote(Sphere &s, Wall w);
	static void Rebote(Sphere& s, Box b);
	static bool Rebote(Sphere& sphere1, Sphere& sphere2);
	static bool Colision(Sphere s, Human h);
	static bool Colision(Shoot s, Wall w);
	static void Colision(Shoot s, Box b);
};