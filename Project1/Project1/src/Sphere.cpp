#include "Sphere.h"
#include "glut.h"

////////////////////////CONSTRUCTOR///////////////////
Sphere::Sphere() {
	//TODO--
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
	position.x = position.x + speed.x * t + 0.5f * aceleration.x * t * t;
	position.y = position.y + speed.y * t + 0.5f * aceleration.y * t * t;
	speed.x = speed.x + aceleration.x * t;
	speed.y = speed.y + aceleration.y * t;
}
	