#include "Sphere.h"


/*Sphere::Sphere() {
	//Damos un valor inicial a la esfera en caso de que el usuario no la configure
	x = y = z = 0;
	radius = 1.0f;
	red = green = blue = 150;

}*/

void Sphere::SetColor(unsigned char r, unsigned char g, unsigned char b) {

	//Configuramos el color
	red = r;
	green = g;
	blue = b;
}

void Sphere::SetPos(float x, float y, float z) {

	//Configuramos la posición
	this->x = x;
	this->y = y;
	this->z = z;
}

float Sphere::GetPos() {
	return x, y, z;
}

void Sphere::SetRadius(float r) {

	//Configuramos el radio
	if (radius <= 0.1f) {
		radius = 0.75f;
	}
	radius = r;
}

float Sphere::GetRadius() {
	return radius;
}

void Sphere::Draw() {

	//Configuramos color, posición y tamaño de la esfera
	glColor3ub(red, blue, green);
	glTranslatef(x, y, z);
	glutSolidSphere(radius, 25, 25);

}

void Sphere::Move(unsigned char key) {

	if (key == 'd' || key == 'D') {
		x+=0.15f;//se mueve a la derecha
	}
	if (key == 'a' || key == 'A') {
		x -= 0.15f; //se mueve a la izquierda
	}
	if (key == 'w' || key == 'W') {
		y += 0.15f; //se mueve hacia arriba
	}
	if (key == 's' || key == 'S') {
		y -= 0.15f; //se mueve hacia abajo
	}
}

void Sphere::MoreSize() {

	//Vamos aumentando el radio hasta un cierto valor
	radius += 0.20f;
	if (radius >= 5.0) {
		radius = 1.0f;
	}
}

void Sphere::LessSize() {

	//Vamos disminuyedo el radio hasta un cierto valor
	radius -= 0.20f;
	if (radius <= 0.5) {
		radius = 1.0f;
	}
}
