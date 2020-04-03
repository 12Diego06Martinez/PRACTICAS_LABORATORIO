#include "glut.h"
#include "Sphere.h"


Sphere::Sphere() {
	//TODO--
	
}

void Sphere::Draw() {
	//TODO--
	glColor3ub(red, green, blue);
	glTranslatef(position.x, position.y, 0);
	glutSolidSphere(radius, 20, 20);
	glTranslatef(-position.x, -position.y, 0);
}

void Sphere::Move(float t) {
	//TODO--
}