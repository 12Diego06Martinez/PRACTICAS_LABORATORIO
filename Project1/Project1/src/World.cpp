#include "World.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
World::World() {
	//Posición del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicialización esfera
	sphere.SetColor(255, 0, 0);
	sphere.SetPos(2, 4);
	sphere.SetRadius(1.5);
	//Inicialización bonus
	bonus.SetPos(5, 0);
	bonus.SetSide(2.5);
	//Inicialización disparo
	shoot.SetPos(5, 5);
	//Inicialización plataforma
	platform.SetLimit1(-5.0f, 9.0f);
	platform.SetLimit2(5.0f, 9.0f);
}

/////////////////////////////MÉTODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,//posición del ojo
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	//Dibujamos objetos
	//box.Draw();
	sphere.Draw();
	bonus.Draw();
	human.Draw();
	shoot.Draw();
	platform.Draw();
	box.Draw();
}

