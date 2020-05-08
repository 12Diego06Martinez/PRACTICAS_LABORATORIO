#include "Humano.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Humano::Humano(){
	altura = 1.8f;
}

Humano::~Humano() {

}
////////////////////////M�TODOS////////////////////////////////
void Humano::Dibujar() {
	//Dibujamos el Humanoo como una esfera
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

void Humano::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Humano::SetVelocidad(float x, float y) {
	velocidad.x = x;
	velocidad.y = y;
}

Vector2D Humano::GetPos() {
	return posicion;
}

float Humano::GetAltura() {
	return altura;
}