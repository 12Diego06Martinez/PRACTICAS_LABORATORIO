#include "World.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
World::World() {
	//Posici�n del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicializaci�n esfera
	sphere.SetColor(255, 0, 0);
	sphere.SetPos(2, 4);
	sphere.SetRadius(1.5);
	//Inicializaci�n bonus
	bonus.SetPos(5, 0);
	bonus.SetSide(2.5);
	//Inicializaci�n caja
	
}

/////////////////////////////M�TODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0);

	//Dibujamos objetos
	sphere.Draw();
	bonus.Draw();
	human.Draw();
}

