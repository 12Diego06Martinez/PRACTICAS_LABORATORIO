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