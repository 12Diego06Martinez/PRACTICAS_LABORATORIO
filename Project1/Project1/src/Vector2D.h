#pragma once
class Vector2D
{
public:
	Vector2D();
	virtual ~Vector2D();
	void SetVector(float xi, float yi);
	float GetX();
	float GetY();
private:
	float x;
	float y;
};

