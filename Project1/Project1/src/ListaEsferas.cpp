#include "ListaEsferas.h"

/////////////////////////////////CONSTRUCTOR////////////////////
ListaEsferas::ListaEsferas() {
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

/////////////////////////////////MÉTODOS////////////////////
bool ListaEsferas::Add(Sphere* e) {
	if (num < MAX_NUM) {
		lista[num] = e;
		num++;
		return true;
	}
	else {
		return false;
	}
}

void ListaEsferas::Draw() {
	for (int i= 0; i < num; i++) {
		lista[num]->Draw();
	}
}

void ListaEsferas::Move(float t) {
	for (int i = 0; i < num; i++) {
		lista[num]->Move(t);
	}
}