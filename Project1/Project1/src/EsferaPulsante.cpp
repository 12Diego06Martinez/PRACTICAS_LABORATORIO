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
	Esfera::SetColor(radio * 255, 255 - radio * 100, 100 + radio * 50);
	/*rojo = radio * 255;  
	verde = 255 - radio * 100; 
	azul = 100 + radio * 50;*/
}

Esfera* EsferaPulsante::Dividir() {
	if (radio_min < 1.0)//si la esfera es muy pequeña no se divide
		return 0;

	//Cuando dividimos la esfera
	radio /= 2.0f;
	pulso *= 2.0f;
	EsferaPulsante* aux = new EsferaPulsante(*this); //copia de la esfera
	aux->SetVel(5, 8); //velocidad de la copia
	SetVel(-5, 8); //velocidad de la original
	return aux;
}