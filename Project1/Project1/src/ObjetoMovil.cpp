#include "ObjetoMovil.h"


//////////////////////////////////CONSTRUCTOR-DESTRUCTOR///////////////////
ObjetoMovil::ObjetoMovil() {

}

ObjetoMovil::~ObjetoMovil() {

}

/////////////////////////////////////METODOS////////////////////////////
void ObjetoMovil::Mueve(float t) {
	//Ecuaciones del movimiento
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void ObjetoMovil::SetPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void ObjetoMovil::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void ObjetoMovil::SetPos(Vector2D pos) {
	posicion.x = pos.x;
	posicion.y = pos.y;
}