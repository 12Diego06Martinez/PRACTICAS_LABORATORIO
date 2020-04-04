#include "Shoot.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Shoot::Shoot() {
	radius = 0.5f;
}

///////////////////////////M�TODOS///////////////////////////
void Shoot::Draw() {
	//Dibujamos el disparo como una esfera
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

void Shoot::Move(float t) {
	//Ecuaciones de movimiento
	position.x = position.x + speed.x * t + 0.5f * aceleration.x * t * t;
	position.y = position.y + speed.y * t + 0.5f * aceleration.y * t * t;
	speed.x = speed.x + aceleration.x * t;
	speed.y = speed.y + aceleration.y * t;
}

void Shoot::SetRadius(float rad) {
	radius = rad;
}

void Shoot::SetPos(float x, float y) {
	position.x = x;
	position.y = y;
}
