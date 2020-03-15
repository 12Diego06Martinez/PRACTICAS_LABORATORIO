#include "World.h"
#include <math.h>

void World::RotateEye() {

	float distance, angle;

	distance = sqrt((x_eye*x_eye) + (z_eye*z_eye));
	angle = atan2(z_eye, x_eye);
	angle += 0.015f;
	x_eye = distance * cos(angle);
	z_eye = distance * sin(angle);

}

void World::Start() {
	//Se llamará a este método en el main

	//Damos valor inicial a la posición del ojo
	x_eye = -10;
	y_eye = 10;
	z_eye = 20;
	//Damos valor inicial al color, posición y radio de la esfera
	sphere_1;//¿LLAMADA AL CONSTRUCTOR?
}

void World::Draw() {
	//Se llamará a este método en la funcion OnDraw

	//Situamos la vista del ojo
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	//Pintamos los objetos
	//Esfera 1
	sphere_1.SetColor(255, 0, 0);
	sphere_1.SetPos(0, 0, 0);
	sphere_1.SetRadius(1.0);
	sphere_1.Draw();

}

void World::Move() {
	//Se llamará a este método en la función Timer

	//TODO--
}

void World::Key(unsigned char key) {
	//Se llamará a este método en la función OnKeyboardDown

	//CAMBIOS DE POSICIÓN
	sphere_1.Move(key);

	//CAMBIOS DE RADIO
	if (key == '+' && sphere_1.GetRadius < 5) {
		sphere_1.MoreSize();//aumenta el radio
	}
	if (key == '-' && sphere_1.GetRadius > 1) {
		sphere_1.LessSize();//disminuye el radio
	}


	//CAMBIOS DE COLOR
	if (key == '1') {
		//Cambio de color a verde
		sphere_1.SetColor(0, 255, 0);
	}
	if (key == '2') {
		//Cambio de color a azul
		sphere_1.SetColor(0, 0, 255);
	if (key == '3') {
		//Cambio de color a rojo
		sphere_1.SetColor(255, 0, 0);
	}
	if (key == '4') {
		//Cambio de color a mix
		sphere_1.SetColor(100, 187, 50);
	}
}





