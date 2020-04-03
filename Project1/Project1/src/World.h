#pragma once
#include "Bonus.h"
#include "Box.h"
#include "Human.h"
#include "Shoot.h"
#include "Sphere.h"
//#include "Wall.h"

class World
{
public:
	World();
	//virtual ~World();
	void Draw();
	void Initialize();
	void Move();
private:
	float x_eye;
	float y_eye;
	float z_eye;
	Bonus bonus;
	Box box;
	Human human;
	Shoot shoot;
	Sphere sphere;
	Wall platform;
};

