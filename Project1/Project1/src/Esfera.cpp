#include "Esfera.h"
#include "glut.h"

////////////////////////CONSTRUCTOR///////////////////
Esfera::Esfera() {
	radio = 1.0f;
	rojo = verde = azul = 255;
	aceleracion.y = -9.8f;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy) {
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	rojo = verde = 255;
	azul = 100;
	aceleracion.y = -9.8f;
}

Esfera::~Esfera() {

}

///////////////////////MÉTODOS///////////////////////
void Esfera::Dibujar() {
	//Dibujamos esfera
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslated(-posicion.x, -posicion.y, 0);
}

void Esfera::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	rojo = r;
	verde = g;
	azul = b;
}

void Esfera::SetRadio(float rad) {
	if (rad > 0) {
		radio = rad;
	}
}

Esfera* Esfera::Dividir() {
	if (radio < 0.1)
		return 0; //no se divide la esfera

	//Cuando dividimos la esfera
	radio /= 2.0;
	Esfera* aux = new Esfera(*this); //copia de la esfera
	aux->SetVel(5, 8); //velocidad mitad copiada
	SetVel(-5, 8); //velocidad mitad original
	return aux;
}