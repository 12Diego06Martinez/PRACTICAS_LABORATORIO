#include "Box.h"
#define R 33
#define G 149
#define B 66

////////////////////////CONSTRUCTOR////////////////////////////
Box::Box() {
	//Techo
	roof.SetColor(R, G, B);
	roof.SetLimit1(-10.0f, 15.0f);
	roof.SetLimit2(10.0f, 15.0f);
	//Suelo
	floor.SetColor(R, G, B);
	floor.SetLimit1(-10.0f, 0.0f);
	floor.SetLimit2(10.0f, 0.0f);
	//Pared izquierda
	left_wall.SetColor(R, G, B);
	left_wall.SetLimit1(-10.0f, 0.0f);
	left_wall.SetLimit2(-10.0f, 15.0f);
	//Pared derecha
	right_wall.SetColor(R, G, B);
	right_wall.SetLimit1(10.0f, 0.0f);
	right_wall.SetLimit2(10.0f, 15.0f);
}

///////////////////////////MÉTODOS///////////////////////////
void Box::Draw() {
	//Dibujamos cuatro paredes accediendo a su método Draw()
	roof.Draw();
	floor.Draw();
	left_wall.Draw();
	right_wall.Draw();
}