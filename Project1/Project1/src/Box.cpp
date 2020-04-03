#include "Box.h"

////////////////////////CONSTRUCTOR////////////////////////////
Box::Box() {
	//TODO--
}

///////////////////////////MÉTODOS///////////////////////////
void Box::Draw() {
	//Dibujamos cuatro paredes accediendo a su método Draw()
	roof.Draw();
	floor.Draw();
	left_wall.Draw();
	right_wall.Draw();
}