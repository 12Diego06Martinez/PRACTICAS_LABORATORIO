#include "EsferaPulsante.h"

/////////////////////////////////////CONSTRUCTOR-DESTRUCTOR/////////////
//EsferaPulsante::EsferaPulsante() {

//}

EsferaPulsante::EsferaPulsante(float p, float r_max, float r_min, float x, float y, float vx, float vy) {
	pulso = p;
	radio_max = r_max;
	radio_min = r_min;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	aceleracion.y = 0;
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