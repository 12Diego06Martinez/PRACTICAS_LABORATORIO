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

/////////////////////////////////M�TODOS////////////////////
bool ListaEsferas::Add(Sphere* e) {
	if (num < MAX_NUM) {
		lista[num] = e;
		num++;
	}
	else
		return false;
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

/*void ListaEsferas::Rebote(Wall wall) {
	for (int i = 0; i < num; i++) {
		Interaction::Rebote(*(lista[i]), wall);
	}
}*/

void ListaEsferas::Rebote() {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			Interaction::Rebote(*(lista[i]), *(lista[j]));
		}
	}
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
		//Recorremos la lista desde la posici�n indicada hasta el 
		//final de la lista. Si por ejemplo eliminamos la esfera en la posici�n 2, movemos 
		//la posici�n 3 a la 2, la 4 a la 3 y as� sucesivamente hasta num
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

Sphere* ListaEsferas::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num-1; 

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos=0;    
	
	return lista[pos];
}