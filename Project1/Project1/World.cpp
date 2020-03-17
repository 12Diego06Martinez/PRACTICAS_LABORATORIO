#include "World.h"
#include <math.h>

void World::Initialize() {
	//Se llamar� a este m�todo en el main

	//Damos valor iniciala la posici�n del ojo
	x_eye = -10;
	y_eye = 10;
	z_eye = 20;
	//Damos valor inicial al color, posici�n y radio de la esfera
	Sphere sphere_1();//�LLAMADA AL CONSTRUCTOR?

}

void World::Draw() {
	//Se llamar� a este m�todo en la funcion OnDraw

	//Situamos la vista del ojo
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	//TODO--Pintamos los objetos
	sphere_1.SetColor(255, 0, 0);
	sphere_1.SetPos(0, 0, 0);
	sphere_1.SetRadius(1.0);
	sphere_1.Draw();
}

void World::Move() {
	//Se llamar� a este m�todo en la funci�n Timer

	//TODO--
}

void World::Key(unsigned char key) {
	//Se llamar� a este m�todo en la funci�n OnKeyboardDown

	//TODO--CAMBIOS DE POSICI�N


	//TODO--CAMBIOS DE RADIO


	//TODO--CAMBIOS DE COLOR


}

void World::RotateEye() {

	/*float distance, angle;

	distance = sqrt((x_eye*x_eye) + (z_eye*z_eye));
	angle = atan2(z_eye, x_eye);
	angle += 0.015f;
	x_eye = distance * cos(angle);
	z_eye = distance * sin(angle);
	*/
}