#include "Interaction.h"

//////////////////////////CONSTRUCTOR/////////////////////////
Interaction::Interaction() {

}

///////////////////////////METODOS///////////////////////////
void Interaction::Rebote(Human& h, Box c) {
	float x_max = c.floor.limit2.x;
	float x_min = c.floor.limit1.x;

	if (h.position.x > x_max) h.position.x = x_max;
	if (h.position.x < x_min) h.position.x = x_min;
}
