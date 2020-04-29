#pragma once
#include "Bonus.h"
#include "Box.h"
#include "Human.h"
#include "Shoot.h"
#include "Sphere.h"
#include "ListaEsferas.h"

class World
{
public:
	World();
	virtual ~World();
	void Draw();
	void Move();
	void Initialize();
	void SpecialKey(unsigned char key);
private:
	float x_eye;
	float y_eye;
	float z_eye;
	Bonus bonus;
	Box box;
	Sphere sphere1;
	Sphere sphere2;
	Human human;
	Shoot shoot;
	Wall platform;
	ListaEsferas spheres;
};

