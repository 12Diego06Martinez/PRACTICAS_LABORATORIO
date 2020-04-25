#include "Sphere.h"
#include "glut.h"

////////////////////////CONSTRUCTOR///////////////////
Sphere::Sphere() {
	radius = 1.0f;
	red = green = blue = 255;
	aceleration.y = -9.8f;
}

Sphere::Sphere(float rad, float x, float y, float vx, float vy) {
	radius = rad;
	position.x = x;
	position.y = y;
	speed.x = vx;
	speed.y = vy;
	red = green = 255;
	blue = 100;
	aceleration.y = -9.8f;
}

Sphere::~Sphere() {

}

///////////////////////MÉTODOS///////////////////////
void Sphere::Draw() {
	//Dibujamos esfera
	glColor3ub(red, green, blue);
	glTranslatef(position.x, position.y, 0);
	glutSolidSphere(radius, 20, 20);
	glTranslated(-position.x, -position.y, 0);
}

void Sphere::Move(float t) {
	//Ecuaciones de movimiento
	position = position + speed * t + aceleration * (0.5f * t * t);
	speed = speed + aceleration * t;
}

void Sphere::SetPos(float x, float y) {
	position.x = x;
	position.y=y;
}

void Sphere::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	red = r;
	green = g;
	blue = b;
}

void Sphere::SetRadius(float rad) {
	if (rad > 0) {
		radius = rad;
	}
}

void Sphere::SetSpeed(float x, float y) {
	speed.x = x;
	speed.y = y;
}