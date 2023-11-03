#include "Vector.h"



Vector::Vector() {
	x = 0;
	y = 0;
}


Vector::Vector(float fx, float fy) {
	x = fx, y = fy;
}


Vector Vector::operator +(Vector const v) {
	return Vector(x + v.x, y + v.y);
}


Vector Vector::operator -(Vector const v) {
	return Vector(x - v.x, y - v.y);
}


Vector Vector::operator *(float const f) {
	return Vector(x * f, y * f);
}


Vector Vector::operator +(float const f) {
	return Vector(x + f, y + f);
}


Vector Vector::operator /(float const f) {
	return Vector(x / f, y / f);
}


bool Vector::operator ==(Vector const v) {
	if (y / y == v.y / v.x && x * x + y * y == v.x * v.x + v.y * v.y) {
		return true;
	}
	else
		return false;
}



float Vector::LengthSquared() {
	return x * x + y * y;
}


float Vector::Length() {
	return sqrt(LengthSquared());
}

void Vector::Show() {
	std::cout << "( " << x << ", " << y << " )" << std::endl;
}

