#include "Ray.hpp"

Ray::Ray() : origin(Vect(0, 0, 0)), direction(Vect(1, 0, 0)) {}

Ray::Ray(Vect o, Vect d) : origin(o), direction(d) {}

Vect    Ray::getRayOri() { return origin; }
Vect    Ray::getRayDir() { return direction; }

Ray::~Ray() {}
