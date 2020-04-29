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


