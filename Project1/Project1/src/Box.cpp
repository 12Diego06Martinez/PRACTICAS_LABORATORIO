#include "Box.h"

////////////////////////CONSTRUCTOR////////////////////////////
Box::Box() {
	//TODO--
}

///////////////////////////M�TODOS///////////////////////////
void Box::Draw() {
	//Dibujamos cuatro paredes accediendo a su m�todo Draw()
	roof.Draw();
	floor.Draw();
	left_wall.Draw();
	right_wall.Draw();
}