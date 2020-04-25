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
	for (int i = 0; i < MAX_NUM; i++) {
		Interaction::Rebote(*(lista[i]), box);
	}
}

void ListaEsferas::Rebote(Wall wall) {
	for (int i = 0; i < MAX_NUM; i++) {
		Interaction::Rebote(*(lista[i]), wall);
	}
}

void ListaEsferas::Rebote() {

}