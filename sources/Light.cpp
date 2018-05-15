#include "Light.hpp"

Light::Light() : origin(Vect(0, 0, 0)), color(Color(1, 1, 1, 0)) {}

Light::Light(Vect o, Color c) : origin(o), color(c) {}



Light::~Light() {}