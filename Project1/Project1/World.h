#pragma once
#include "glut.h"
#include "Sphere.h"

class World
{
public:
	//World();
	//~World();
	void RotateEye();
	void Initialize();
	void Draw();
	void Move();
	void Key(unsigned char key);

private:
	float x_eye;
	float y_eye;
	float z_eye;
	Sphere sphere_1;

};