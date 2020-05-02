#include "InteraccionListas.h"

///////////////////////////////CONSTRUCTOR-DESTRUCTOR//////////////
InteraccionListas::InteraccionListas() {

}

InteraccionListas::~InteraccionListas() {

}

/////////////////////////////////////METODOS////////////////////
void InteraccionListas::Rebote(ListaEsferas& s, Box b) {
	for (int i = 0; i < s.GetNum(); i++) {
		Interaction::Rebote(*(s[i]), b);
	}
}

void InteraccionListas::Rebote(ListaEsferas& s, Wall w) {
	for (int i = 0; i < s.GetNum(); i++) {
		Interaction::Rebote(*(s[i]), w);
	}
}