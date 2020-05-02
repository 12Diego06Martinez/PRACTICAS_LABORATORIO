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

void InteraccionListas::Rebote(ListaEsferas& s) {
	for (int i = 0; i < s.GetNum(); i++) {
		for (int j = 0; j < s.GetNum(); j++) {
			Interaction::Rebote(*(s[i]), *(s[j]));
		}
	}
}