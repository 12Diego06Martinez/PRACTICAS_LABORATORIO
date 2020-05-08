#include "Pared.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Pared::Pared() {
	rojo = verde = azul = 255; //color por defecto=blanco
}

Pared::~Pared() {

}
///////////////////////////MÉTODOS///////////////////////////
void Pared::Dibujar() {
	//Una Pared es un polígono
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x, limite1.y, 10);
		glVertex3d(limite2.x, limite2.y, 10);
		glVertex3d(limite2.x, limite2.y, -10);
		glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	rojo = r;
	verde = g;
	azul = b;
}

void Pared::SetLimites(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

float Pared::Distancia(Vector2D point, Vector2D* direction) {
/*Calculo de distancia de una Pared a un punto, adicionalmente 
se modifica el valor de un vector direccion que contendrá el vector 
unitario saliente que indica la direccion de la recta más corta entre el punto y la Pared. */
	Vector2D u=(point-limite1);  
	Vector2D v=(limite2-limite1).Unitario(); 
	float longitud=(limite1-limite2).Modulo(); 
	Vector2D dir;  
	float valor=u*v;  
	float distancia=0; 

	if (valor < 0)   
		dir = u; 
	else if (valor > longitud)  
		dir = (point - limite2); 
	else   
		dir = u - v * valor;  

	distancia = dir.Modulo();  
	if (direction != 0)   
		*direction=dir.Unitario();  
	return distancia;
}