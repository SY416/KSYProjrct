#pragma once
#include <iostream>

class Vector
{
public:
	float x, y;
	Vector();
	Vector(float fx, float fy);
	Vector operator +(Vector const v);
	Vector operator -(Vector const v);
	Vector operator *(float const f);
	Vector operator +(float const f);
	Vector operator /(float const f);
	bool operator ==(Vector const v);
	
	float LengthSquared();
	float Length();

	void Show();
};

