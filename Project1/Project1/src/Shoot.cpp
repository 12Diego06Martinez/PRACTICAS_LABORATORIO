#include "glut.h"
#include "Shoot.h"


Shoot::Shoot() {
	//TODO--
}

void Shoot::Draw() {
	//TODO--
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

void Shoot::Move(float t){
	//TODO--
}