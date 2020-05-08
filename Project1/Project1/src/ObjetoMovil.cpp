#include "ObjetoMovil.h"

void ObjetoMovil::Mueve(float t) {
	//Ecuaciones del movimiento
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}