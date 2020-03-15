#include "World.h"
#include <math.h>

void World::RotateEye() {

	float distance, angle;

	distance = sqrt((x_eye*x_eye) + (z_eye*z_eye));
	angle = atan2(z_eye, x_eye);
	angle += 0.015f;
	x_eye = distance * cos(angle);
	z_eye = distance * sin(angle);

}