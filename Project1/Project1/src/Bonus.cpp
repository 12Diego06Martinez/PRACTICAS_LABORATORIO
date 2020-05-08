#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"



////////////////////////CONSTRUCTOR////////////////////////////
Bonus::Bonus() {
	lado = 2;
	aceleracion.y = -9.8f;
}

Bonus::~Bonus() {

}
///////////////////////////MÉTODOS///////////////////////////
void Bonus::Dibujar() {
	//Dibujamos el bonus como un cubo de color aleatorio
	glPushMatrix();  
	glTranslatef(posicion.x, posicion.y, 0);  
	glRotatef(30, 1, 1, 1);  
	glColor3f(	rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, 
				rand() / (float)RAND_MAX); //color aleatorio    
		glutSolidCube(lado);  
	glPopMatrix(); 
}

void Bonus::Mueve(float t) {
	//Definimos las ecuaciones de movimiento
	posicion = posicion	+ velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Bonus::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Bonus::SetSide(float s) {
	if (s > 0) {
		lado = s;
	}
}