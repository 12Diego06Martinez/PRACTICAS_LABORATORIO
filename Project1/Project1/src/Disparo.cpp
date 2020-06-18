#include "Disparo.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Disparo::Disparo() {
	radio = 0.25f;
	velocidad.y = 5.0f;
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
	glutSolidSphere(radio, 100, 100);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
	//Dibujamos la estela como una línea recta
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3d(posicion.x, 0, 0);
	glVertex3d(posicion.x, posicion.y, 0);
	glVertex3d(posicion.x + 0.05, posicion.y, 0);
	glVertex3d(posicion.x + 0.05, 0, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	/*glDisable(GL_LIGHTING);
	glColor3ub(0, 255, 0);
	glBegin(GL_LINES);
	glVertex2f(origen.x, origen.y);
	glVertex2f(posicion.x, posicion.y);
	glEnd();
	glEnable(GL_LIGHTING);
	*/
}

void Disparo::SetRadio(float rad) {
	if (rad > 0) {
		radio = rad;
	}
}

void Disparo::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Disparo::SetOrigen(Vector2D o) {
	origen.x = o.x;
	origen.y = o.y;
}

void Disparo::SetPos(Vector2D pos) {
	posicion = pos;
	
}
