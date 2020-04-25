#include "ListaEsferas.h"

/////////////////////////////////CONSTRUCTOR////////////////////
ListaEsferas::ListaEsferas() {
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaEsferas::~ListaEsferas() {

}

/////////////////////////////////MÉTODOS////////////////////
bool ListaEsferas::Add(Sphere* e) {
	if (num < MAX_NUM) {
		lista[num++] = e;
	}
	else {
		return false;
	}
	return true;
}

void ListaEsferas::Draw() {
	for (int i= 0; i < num; i++) {
		lista[i]->Draw();
	}
}

void ListaEsferas::Move(float t) {
	for (int i = 0; i < num; i++) {
		lista[i]->Move(t);
	}
}

void ListaEsferas::Rebote(Box box) {
	for (int i = 0; i < num; i++) {
		Interaction::Rebote(*(lista[i]), box);
	}
}

void ListaEsferas::Rebote(Wall wall) {
	for (int i = 0; i < num; i++) {
		Interaction::Rebote(*(lista[i]), wall);
	}
}

void ListaEsferas::Rebote() {
	//TODO--
}

void ListaEsferas::Destroy() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaEsferas::Delete(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;
	for (int i=index; i < num; i++) {
		/*Recorremos la lista desde la posición indicada hasta el 
		final de la lista. Si por ejemplo eliminamos la esfera en la posición 2, movemos 
		la posición 3 a la 2, la 4 a la 3 y así sucesivamente hasta num*/
		lista[i] = lista[i + 1];
	}

}

void ListaEsferas::Delete(Sphere* sphere) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == sphere) {
			Delete(i);
			return;
		}
	}
}

Sphere* ListaEsferas::Colision(Human& h) {
	for (int i = 0; i < num; i++) {
		if (Interaction::Colision(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}