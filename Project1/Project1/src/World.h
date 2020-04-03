#pragma once
#include "Box.h"
#include "Human.h"
#include "Bonus.h"
#include "Shoot.h"
#include "Sphere.h"

class World
{
public:
	//World();
	//~World();
	void Draw();
	void Move(float t);
	void Initialize();
private:
	float x_eye;
	float y_eye;
	float z_eye;
	Shoot shoot;
	Sphere sphere;
	Human human;
	Box box;
	Bonus bonus;
	Wall platform;
};