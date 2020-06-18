#include "Humano.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Humano::Humano(){
	altura = 1.8f;
}

Humano::~Humano() {

}
////////////////////////MÉTODOS////////////////////////////////
void Humano::Dibujar() {
	//Dibujamos el Humanoo como una esfera
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}