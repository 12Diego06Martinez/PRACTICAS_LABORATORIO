#pragma once
#include "Wall.h"


class Box
{
public:
	Box();
	virtual ~Box();
	void Draw();
private:
	Wall floor;
	Wall roof;
	Wall right;
	Wall left;
};

