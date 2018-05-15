#include "Vect.hpp"

Vect::Vect() : x(0), y(0), z(0) {}

Vect::Vect(double x, double y, double z) : x(x), y(y), z(z) {}

double      Vect::getVectX() { return x; }
double      Vect::getVectY() { return y; }
double      Vect::getVectZ() { return z; }

Vect		Vect::mult(int k) {
	return Vect (x * k, y * k, z * k);
}

Vect		Vect::negative() {
	return Vect (-x, -y, -z);
}

double		Vect::magnitude() {
	return sqrt((x * x) + (y * y) + (z * z));
}

Vect		Vect::normalize() {
	return Vect (x / this->magnitude(), y / this->magnitude(), z / this->magnitude());
}

Vect		Vect::add(Vect v1) {
	return Vect (x + v1.getVectX(), y + v1.getVectY(), z + v1.getVectZ());
}

double		Vect::dotProduct(Vect v1) {
	return x * v1.getVectX() + y * v1.getVectY() + z * v1.getVectZ();
}

Vect		Vect::crossProduct(Vect v1) {
	return Vect ((y * v1.getVectZ() - z * v1.getVectY()), (z * v1.getVectX() - x * v1.getVectZ()),
					(x * v1.getVectY() - y * v1.getVectX()));
}

Vect::~Vect() {}