#include "Interaction.h"

//////////////////////////CONSTRUCTOR/////////////////////////
Interaction::Interaction() {

}

///////////////////////////METODOS///////////////////////////
void Interaction::Rebote(Human& h, Box b) {
	float x_max = b.floor.limit2.x;
	float x_min = b.floor.limit1.x;

	if (h.position.x > x_max) h.position.x = x_max;
	if (h.position.x < x_min) h.position.x = x_min;
}

bool Interaction::Rebote(Sphere& s, Wall w) {
	Vector2D dir;  
	float dif = w.Distance(s.position, &dir) - s.radius; //calcula la distancia entre la pared y la esfera y le resta el radio  
	if (dif <= 0.0f) { //han chocado ya 
		//Vf=Vi-2(Vi*direccion)*direccion
		Vector2D v_inicial = s.speed;   
		s.speed = v_inicial - dir * 2.0 * (v_inicial * dir);  
		s.position = s.position - dir * dif;   
		return true; 
	}  
	return false;
}

bool Interaction::Rebote(Sphere& s, Box b) {
	//--TODO
	return false;
}
