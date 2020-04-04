#include "Box.h"

////////////////////////CONSTRUCTOR////////////////////////////
Box::Box() {
	//Techo
	roof.SetColor(0,100,200);
	//Suelo
	floor.SetColor(0, 100, 200);
	//Pared izquierda
	left_wall.SetColor(0, 120, 200);
	//Pared derecha
	right_wall.SetColor(0, 120, 200);
}

///////////////////////////MÉTODOS///////////////////////////
void Box::SetBox() {
	//Techo
	roof.SetLimits(-10.0f, 15.0f, 10.0f, 15.0f);
	//Suelo
	floor.SetLimits(-10.0f, 0.0f, 10.0f, 0.0f);
	//Pared izquierda
	left_wall.SetLimits(-10.0f, 0.0f, -10.0f, 15.0f);
	//Pared derecha
	right_wall.SetLimits(10.0f, 0.0f, 10.0f, 15.0f);
}

void Box::Draw() {
	//Dibujamos cuatro paredes accediendo a su método Draw()
	roof.Draw();
	floor.Draw();
	left_wall.Draw();
	right_wall.Draw();
}

