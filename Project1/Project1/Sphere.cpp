#include "Sphere.h"

Sphere::Sphere() {
	//Constructor
	x = y = z = 2;
	red = green = blue = 255;
	radius = 2;
}

void Sphere::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	//Configuramos el color
	red = r;
	green = g;
	blue = b;
}

void Sphere::SetPos(float xi, float yi, float zi) {
	//Configuramos la posición
	x = xi;
	y = yi;
	z = zi;
}

void Sphere::SetRadius(float r) {
	//Configuramos el radio
	radius = r;
	if (radius <= 0.1f) {
		radius = 0.75f;
	}
	
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

void Sphere::Move() {

	radius += 0.1f;
	if (radius > 5) {
		radius = 0.75f;
	}
}