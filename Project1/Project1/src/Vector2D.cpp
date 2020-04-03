#include "Vector2D.h"

Vector2D::Vector2D() {
	//pos=origen, vel=parado, acel=no
	x = y = 0;
}

void Vector2D::SetVector(float xi, float yi) {
	x = xi;
	y = yi;
}

float Vector2D::GetX() {
	return x;
}

float Vector2D::GetY() {
	return y;
}