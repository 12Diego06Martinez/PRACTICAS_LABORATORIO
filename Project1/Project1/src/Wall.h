#pragma once
#include "Vector2D.h"

class Wall
{
public:
	Wall();
	//virtual ~Wall();
	void Draw();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);
	void SetLimits(float x1, float y1, float x2, float y2);
	float Distance(Vector2D point, Vector2D* direction = 0);
	friend class Interaction;
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	Vector2D limit1;
	Vector2D limit2;
};

