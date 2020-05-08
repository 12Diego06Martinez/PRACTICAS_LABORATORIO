#include "ListaDisparos.h"

/////////////////////////////////CONSTRUCTOR-DESTRUCTOR////////////////
ListaDisparos::ListaDisparos() {
	num = 0;
	for (int i = 0; i < MAX_Disparo; i++) {
		lista[i] = 0;
	}
}

ListaDisparos::~ListaDisparos() {

}

/////////////////////////////METODOS///////////////////////////
bool ListaDisparos::Agregar(Disparo* d) {
	if (num < MAX_Disparo) {
		lista[num] = d;
		num++;
	}
	else
		return false;
	return true;
}

void ListaDisparos::Mueve(float t) {
	for (int i = 0; i < num; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaDisparos::Dibujar() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibujar();
	}
}

void ListaDisparos::Destruir() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

Disparo* ListaDisparos::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}
