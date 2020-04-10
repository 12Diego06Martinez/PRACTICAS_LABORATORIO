#include "Box.h"

////////////////////////CONSTRUCTOR////////////////////////////
Box::Box() {
	//Techo
	roof.SetColor(0,200,100);
	roof.SetLimits(-10.0f, 15.0f, 10.0f, 15.0f);
	//Suelo
	floor.SetColor(0,200, 100);
	floor.SetLimits(-10.0f, 0.0f, 10.0f, 0.0f);
	//Pared izquierda
	left_wall.SetColor(0, 220, 100);
	left_wall.SetLimits(-10.0f, 0.0f, -10.0f, 15.0f);
	//Pared derecha
	right_wall.SetColor(0, 220, 100);
	right_wall.SetLimits(10.0f, 0.0f, 10.0f, 15.0f);
}

///////////////////////////MÉTODOS///////////////////////////
void Box::Draw() {
	//Dibujamos cuatro paredes accediendo a su método Draw()
	roof.Draw();
	floor.Draw();
	left_wall.Draw();
	right_wall.Draw();
}

