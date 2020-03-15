#pragma once
#include "glut.h"

class World 
{
public:
	World ();
	~World ();
	void RotateEye();

private:
	float x_eye;
	float y_eye;
	float z_eye;

};

