#include "World.h"
#include <math.h>

void World::Initialize() {
	//Se llamará a este método en el main

	//Damos valor iniciala la posición del ojo
	x_eye = -10.0;
	y_eye = 10.0;
	z_eye = 20.0;

	//Damos valor inicial al color, posición y radio de la esfera definidos en el constructor
	sphere_1.SetRadius(2);
	sphere_1.SetColor(0, 255, 255);
	sphere_1.SetPos(2, 2, 2);
	sphere_2.SetColor(255, 0, 0);
	sphere_2.SetPos(0, 5, -2);
	sphere_2.SetRadius(1.0);

}

void World::Draw() {
	//Se llamará a este método en la funcion OnDraw

	//Situamos la vista del ojo
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	//Voy a dibujar un suelo para comprobar la rotacion de la camara
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3f(-5.0f, 0, -5.0f);
		glVertex3f(-5.0f, 0, 5.0f);
		glColor3ub(255, 255, 0);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);

	//Pintamos los objetos
	sphere_1.Draw();
	sphere_2.Draw();
}

void World::Move() {
	//Se llamará a este método en la función Timer

	//Actualización posición cámara
	float distance = sqrt(((double)x_eye * (double)x_eye) + ((double)z_eye * (double)z_eye));
	float angle = atan2(z_eye, x_eye);
	angle += 0.015f;
	x_eye = distance * cos(angle);
	z_eye = distance * sin(angle);

	//Actualización esfera
	sphere_1.Move();
}

void World::Key(unsigned char key) {
	//Se llamará a este método en la función OnKeyboardDown

	float radius = sphere_2.GetRadius();
	
	//CAMBIOS DE POSICIÓN
	sphere_2.ChangePos(key);

	//TODO--CAMBIOS DE RADIO
	if (key == '+' && sphere_2.GetRadius() <= 5.0) {
		sphere_2.SetRadius(radius += 0.15); //aumenta radio
	}

	if (key == '-' && sphere_2.GetRadius() >= 1.0) {
		//float radius = sphere_2.GetRadius();
		sphere_2.SetRadius(radius -= 0.15); //disminuye radio
	}
	

	//CAMBIOS DE COLOR
	if (key == '0') {
		sphere_1.SetColor(255, 255, 255); //ambas esferas blancas
		sphere_2.SetColor(255, 255, 255);
	}
	if (key == '1') {
		sphere_1.SetColor(255, 0, 0); //e1 rojo
	}
	if (key == '2') {
		sphere_1.SetColor(0, 255, 0); //e1 verde
	}
	if (key == '3') {
		sphere_1.SetColor(0, 0, 255); //e1 azul
	}
	if (key == '4') {
		sphere_2.SetColor(255, 0, 0); //e2 roja
	}
	if (key == '5') {
		sphere_2.SetColor(0, 255, 0); //e2 verde
	}
	if (key == '6') {
		sphere_2.SetColor(0, 0, 255); //e2 azul
	}
}

