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
	//Inicializaci�n disparo
	shoot.SetPos(5, 5);
	//Inicializaci�n plataforma
	platform.SetLimit1(-5.0f, 9.0f);
	platform.SetLimit2(5.0f, 9.0f);
}

/////////////////////////////M�TODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,//posici�n del ojo
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientaci�n del mundo hacia arriba

	//Dibujamos objetos
	//box.Draw();
	sphere.Draw();
	bonus.Draw();
	human.Draw();
	shoot.Draw();
	platform.Draw();
	box.Draw();
}

