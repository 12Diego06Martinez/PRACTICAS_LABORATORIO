#include "Human.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Human::Human(){
	//TODO--
}

////////////////////////MÉTODOS////////////////////////////////
void Human::Draw() {
	//Dibujamos el humano como una esfera
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(height, 20, 20);
	glPopMatrix();
}

void Human::Move(float t) {
	//Ecuaciones del movimiento
	position.x = position.x + speed.x * t + 0.5f * aceleration.x * t * t;
	position.y = position.y + speed.y * t + 0.5f * aceleration.y * t * t;
	speed.x = speed.x + aceleration.x * t;
	speed.y = speed.y + aceleration.y * t;
}