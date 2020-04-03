#include "glut.h"
#include "Human.h"


Human::Human() {
	//TODO--
}

void Human::Draw() {
	//TODO--
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glutSolidSphere(height, 20, 20);
	glPopMatrix();
}

void Human::Move(float t) {
	//TODO--
}
