#pragma once
#include "Wall.h"

class Box
{
public:
	Box();
	//virtual ~Box();
	void Draw();
	friend class Interaction;
private:
	Wall roof;
	Wall floor;
	Wall left_wall;
	Wall right_wall;
};

