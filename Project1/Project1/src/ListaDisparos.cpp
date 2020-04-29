#include "ListaDisparos.h"

/////////////////////////////////CONSTRUCTOR-DESTRUCTOR////////////////
ListaDisparos::ListaDisparos() {
	num = 0;
	for (int i = 0; i < MAX_SHOOT; i++) {
		lista[i] = 0;
	}
}

ListaDisparos::~ListaDisparos() {

}

/////////////////////////////METODOS///////////////////////////
bool ListaDisparos::Add(Shoot* s) {
	if (num < MAX_SHOOT) {
		lista[num] = s;
		num++;
	}
	else
		return false;
	return true;
}

void ListaDisparos::Move(float t) {
	for (int i = 0; i < num; i++) {
		lista[i]->Move(t);
	}
}

void ListaDisparos::Destroy() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaDisparos::Colision(Wall w) {
//-TODO
}

void ListaDisparos::Colision(Box b) {
	//--TODO
}
