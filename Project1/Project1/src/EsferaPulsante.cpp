#include "EsferaPulsante.h"

/////////////////////////////////////CONSTRUCTOR-DESTRUCTOR/////////////
EsferaPulsante::EsferaPulsante() {
	pulso = 0.5f;
	radio_max = 2.0f;
	radio_min = 0.5f;
	aceleracion.y = 0.0f;
	posicion.y = 5.0f;
}
EsferaPulsante::~EsferaPulsante() {

}

///////////////////////////////////METODOS////////////////////
void EsferaPulsante::Mueve(float t) {

	Esfera::Mueve(t);

	if (radio > radio_max)   
		pulso = -pulso;

	if (radio < radio_min)   
		pulso = -pulso;

	radio += pulso * t;
	rojo = radio * 255;  
	verde = 255 - radio * 100; 
	azul = 100 + radio * 50;
}