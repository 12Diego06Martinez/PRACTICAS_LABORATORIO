#include "Caja.h"

////////////////////////CONSTRUCTOR////////////////////////////
Caja::Caja() {
	//Techo
	tejado.SetColor(0,200,100);
	tejado.SetLimites(-10.0f, 15.0f, 10.0f, 15.0f);
	//Suelo
	suelo.SetColor(0,200, 100);
	suelo.SetLimites(-10.0f, 0.0f, 10.0f, 0.0f);
	//Pared izquierda
	izquierda.SetColor(0, 220, 100);
	izquierda.SetLimites(-10.0f, 0.0f, -10.0f, 15.0f);
	//Pared derecha
	derecha.SetColor(0, 220, 100);
	derecha.SetLimites(10.0f, 0.0f, 10.0f, 15.0f);
}

Caja:: ~Caja() {

}

///////////////////////////MÉTODOS///////////////////////////
void Caja::Dibujar() {
	//Dibujamos cuatro Paredes accediendo a su método Dibujar()
	tejado.Dibujar();
	suelo.Dibujar();
	izquierda.Dibujar();
	derecha.Dibujar();
}


