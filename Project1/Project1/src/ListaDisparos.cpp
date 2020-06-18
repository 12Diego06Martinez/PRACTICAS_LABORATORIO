#include "ListaDisparos.h"
#include "Interaccion.h"

/////////////////////////////////CONSTRUCTOR-DESTRUCTOR////////////////
ListaDisparos::ListaDisparos() {
	for (int i = 0; i < MAX_Disparo; i++) {
		lista[i] = 0;
	}
	num = 0;
}

ListaDisparos::~ListaDisparos() {

}

/////////////////////////////METODOS///////////////////////////
bool ListaDisparos::Agregar(Disparo* d) {
	if (num < MAX_Disparo) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == d) {
				return false;
			}
		}
		lista[num] = d;
		num++;
		return true;
	}
	else
		return false;
	
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

void ListaDisparos::SetPos(float x, float y) {
	for (int i = 0; i < num; i++) {
		lista[i]->SetPos(x, y);
	}
}

void ListaDisparos::SetVel(float vx, float vy) {
	for (int i = 0; i < num; i++) {
		lista[i]->SetVel(vx, vy);
	}
}

void ListaDisparos::Delete(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;
	for (int i = index; i < num; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaDisparos::Delete(Disparo* disparo) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == disparo) {
			Delete(i);
			return;
		}
	}
}
