#include "Human.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Human::Human(){
	height = 1.8f;
}

////////////////////////MÉTODOS////////////////////////////////
void Human::Draw() {
	//Dibujamos el humano como una esfera
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(height, 20, 20);
	glPopMatrix();
}

void Human::Move(float t) {
	//Ecuaciones del movimiento
	position = position + speed * t + aceleration * (0.5f * t * t);
	speed = speed + aceleration * t;
}

void Human::SetPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Human::SetSpeed(float x, float y) {
	speed.x = x;
	speed.y = y;
}

Vector2D Human::GetPos() {
	return position;
}

float Human::GetHeight() {
	return height;
}