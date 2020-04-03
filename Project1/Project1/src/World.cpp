#include "World.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
World::World() {
	//TODO--
}

/////////////////////////////MÉTODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0);

	//Dibujamos objetos
	
}

