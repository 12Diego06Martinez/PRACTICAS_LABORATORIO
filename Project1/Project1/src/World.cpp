#include "World.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
World::World() {
	
}

/////////////////////////////MÉTODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,//posición del ojo
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	//Dibujamos objetos
	sphere.Draw();
	bonus.Draw();
	human.Draw();
	shoot.Draw();
	platform.Draw();
	box.Draw();
}

void World::Move() {
	sphere.Move(0.025f);
	bonus.Move(0.025f);
	human.Move(0.025f);
	shoot.Move(0.025f);
}

void World::Initialize() {
	//Posición del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicialización esfera
	sphere.SetColor(255, 0, 0);
	sphere.SetPos(2, 4);
	sphere.SetRadius(1.5);
	//Inicialización bonus
	bonus.SetPos(5, 10);
	bonus.SetSide(2.5);
	//Inicialización disparo
	shoot.SetPos(5, 5);
	//Inicialización plataforma
	platform.SetLimits(-5.0f, 9.0f, 5.0f, 9.0f);
	//Inicialización caja
	box.SetBox();
}

