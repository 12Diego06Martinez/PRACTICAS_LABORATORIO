#include "Disparo.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Disparo::Disparo() {
	radio = 0.5f;
	aceleracion.y = 2.0f;
}

Disparo::Disparo(float rad, float x, float y, float vx, float vy) {
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
}

Disparo::~Disparo() {

}
///////////////////////////MÉTODOS///////////////////////////
void Disparo::Dibujar() {
	//Dibujamos el disparo como una esfera
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
	//Dibujamos la estela como una línea recta
	glDisable(GL_LIGHTING);
	glColor3ub(0, 255, 0);
	glBegin(GL_LINES);
	glVertex2f(origen.x, origen.y);
	glVertex2f(posicion.x, posicion.y);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Disparo::SetRadio(float rad) {
	if (rad > 0) {
		radio = rad;
	}
}

void Disparo::SetPos(float x, float y) {
	posicion.x = origen.x = x;
	posicion.y = origen.y =y;
}

void Disparo::Setvelocidad(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Disparo::SetAcel(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
