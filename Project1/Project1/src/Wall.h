#pragma once
#include "Vector2D.h"

class Wall
{
public:
	Wall();
	//virtual ~Wall();
	void Draw();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetLimit1(float x, float y);
	void SetLimit2(float x, float y);
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	Vector2D limit1;
	Vector2D limit2;
};

