#pragma once
#include "glut.h"
#include "Sphere.h"

class World 
{
public:
	Sphere idk;
	Sphere idk2;
	World ();
	~World ();
	void RotateEye();

private:
	float x_eye;
	float y_eye;
	float z_eye;

};

