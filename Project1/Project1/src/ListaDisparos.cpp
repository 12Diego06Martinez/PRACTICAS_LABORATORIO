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

void ListaDisparos::Draw() {
	for (int i = 0; i < num; i++) {
		lista[i]->Draw();
	}
}

void ListaDisparos::Destroy() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

Shoot* ListaDisparos::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}

/*void ListaDisparos::Colision(Box b) {
	for (int i = 0; i < num; i++) {
		if (Interaction::Colision(*(lista[i]), b)) {
			lista[i]->SetSpeed(0, 0);
			lista[i]->SetAcel(0, 0);
		}
	}
}*/
