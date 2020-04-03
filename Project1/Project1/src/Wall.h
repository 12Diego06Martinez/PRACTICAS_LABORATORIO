#pragma once
#include "Vector2D.h"

class Wall
{
public:
	Wall();
	//virtual ~Wall();
	void Draw();
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	Vector2D limit1;
	Vector2D limit2;
};

