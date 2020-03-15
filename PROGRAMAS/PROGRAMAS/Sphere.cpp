#include "Sphere.h"

void Sphere::Draw() {

	//Setting color, size and position
	glColor3ub(red, blue, green);
	glTranslatef(x, y, z);
	glutSolidSphere(radius, 25, 25);

}

void Sphere::Move() {

	//Radius changing 
	radius += 0.15f;
	if (radius >= 5) {
		radius = 0.75f;
	}
}

void Sphere::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	
	//Changing color
	red = r;
	green = g;
	blue = b;
}

void Sphere::SetPos(float x, float y, float z) {

	//Changing position 
	this->x = x;
	this->y = y;
	this->z = z;
}

void Sphere::SetRadius(float r) {

	//Changing radius
	if (radius <= 0.1f) {
		radius = 0.75f;
	}
	radius = r;
}