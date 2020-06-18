#include "InteraccionListas.h"
#include "ETSIDI.h"

///////////////////////////////CONSTRUCTOR-DESTRUCTOR//////////////
InteraccionListas::InteraccionListas() {

}

InteraccionListas::~InteraccionListas() {

}

/////////////////////////////////////METODOS////////////////////
void InteraccionListas::Rebote(ListaEsferas& e, Caja c) {
	for (int i = 0; i < e.GetNum(); i++) {
		Interaccion::Rebote(*(e[i]), c);
	}
}

void InteraccionListas::Rebote(ListaEsferas& e, Pared p) {
	for (int i = 0; i < e.GetNum(); i++) {
		Interaccion::Rebote(*(e[i]), p);
	}
}

void InteraccionListas::Rebote(ListaEsferas& e) {
	for (int i = 0; i < e.GetNum(); i++) {
		for (int j = 0; j < e.GetNum(); j++) {
			Interaccion::Rebote(*(e[i]), *(e[j]));
		}
	}
}

Esfera* InteraccionListas::Colision(ListaEsferas& e, Humano& h) {
	for (int i = 0; i < e.GetNum(); i++) {
		if (Interaccion::Colision(*(e[i]), h))
			return e[i];
	}
	return 0;
}

void InteraccionListas::Colision(ListaDisparos& d, Pared p) {
	for (int i = 0; i < d.GetNum(); i++) {
		if (Interaccion::Colision(*(d[i]), p)) {
			d[i]->SetVel(0, 0);
			//d[i]->SetAcel(0, 0);
		}
	}
}

void InteraccionListas::Colision(ListaDisparos& d, Caja c) {
	for (int i = 0; i < d.GetNum(); i++) {
		if (Interaccion::Colision(*(d[i]), c)) {
			d[i]->SetVel(0, 0);
			//d[i]->SetAcel(0, 0);
		}
	}
}

void InteraccionListas::Colision(ListaDisparos& d, ListaEsferas& e) {
	for (int i = 0; i < e.GetNum(); i++) {
		for (int j = 0; j < d.GetNum(); j++) {
			if (Interaccion::Colision(*d[j], *e[i])) {
				Esfera* esf = e[i]->Dividir();
				if (esf == 0)
					e.Delete(e[i]);
				else
					e.Agregar(esf);
				d.Delete(d[j]);
				//d.SetPos(0, 0);
				//d.SetVel(0, 10);
				ETSIDI::play("sonidos/impacto_balas.wav");
				break;
			}
		}
		
	}
}