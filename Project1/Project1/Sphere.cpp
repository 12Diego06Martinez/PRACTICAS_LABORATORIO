#include "Sphere.h"

Sphere::Sphere() {
	//Constructor
	x = y = z = 0;
	radius = 1.0f;
	red = green = blue = 150;

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
	if (radius <= 0.1f) {
		radius = 0.75f;
	}
	radius = r;
}

void Sphere::Draw() {
	//Configuramos color, posición y tamaño de la esfera
	glColor3ub(red, blue, green);
	glTranslatef(x, y, z);
	glutSolidSphere(radius, 25, 25);
}

void Sphere::Move() {


}