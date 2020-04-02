#include "Sphere.h"

Sphere::Sphere() {
	//Constructor: posicion (2,2,2), color blanco y radio=2
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
	//Aumenta radio de la esfera automaticamente hasta un valor determinado
	radius += 0.1f;
	if (radius > 5) {
		radius = 0.75f;
	}
}

//Previamente hice esta funcionalidad en la clase Mundo mediante Getters 
//para obtener la posición de la esfera y modificarla, pero me ha parecido
//más sencillo realizar el propio método en la clase e invocarlo en la clase Mundo posteriormente

void Sphere::ChangePos(unsigned char key) {
	if (key == 'w' || key == 'W') {
		y += 0.1; //mueve arriba
	}
	if (key == 'd' || key == 'D') {
		x += 0.1; //mueve derecha
	}
	if (key == 's' || key == 'S') {
		y -= 0.1; //mueve abajo
	}
	if (key == 'a' || key == 'A') {
		x -= 0.1; //mueve izquierda
	}
}