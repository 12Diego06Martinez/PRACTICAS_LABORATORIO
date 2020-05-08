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
bool ListaEsferas::Agregar(Esfera* e) {
	if (num < MAX_NUM) {
		lista[num] = e;
		num++;
	}
	else
		return false;
	return true;
}

void ListaEsferas::Dibujar() {
	for (int i= 0; i < num; i++) {
		lista[i]->Dibujar();
	}
}

void ListaEsferas::Mueve(float t) {
	for (int i = 0; i < num; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaEsferas::Destruir() {
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
		//Recorremos la lista desde la posición indicada hasta el 
		//final de la lista. Si por ejemplo eliminamos la esfera en la posición 2, Muevemos 
		//la posición 3 a la 2, la 4 a la 3 y así sucesivamente hasta num
		lista[i] = lista[i + 1];
	}
}

void ListaEsferas::Delete(Esfera* esfera) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == esfera) {
			Delete(i);
			return;
		}
	}
}

Esfera* ListaEsferas::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num-1; 

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos=0;    
	
	return lista[pos];
}