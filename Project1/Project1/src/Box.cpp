#include "Box.h"
#define R 50
#define G 255
#define B 50

////////////////////////CONSTRUCTOR////////////////////////////
Box::Box() {
	//TODO--
}

///////////////////////////MÉTODOS///////////////////////////
void Box::Draw() {
	//Dibujamos cuatro paredes accediendo a su método Draw()
	roof.SetColor(R, G, B);
	floor.SetColor(R, G, B);
	left_wall.SetColor(R, G, B);
	right_wall.SetColor(R, G, B);
	roof.Draw();
	floor.Draw();
	left_wall.Draw();
	right_wall.Draw();
}