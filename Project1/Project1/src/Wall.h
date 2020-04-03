#pragma once
#include "Vector2D.h"

class Wall
{
public:
	Wall();
	//virtual ~Wall();
	void Draw();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	Vector2D limit1;
	Vector2D limit2;
};

